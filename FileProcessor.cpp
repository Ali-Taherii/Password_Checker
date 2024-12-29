#define TINYFILEDIALOGS_IMPLEMENTATION
#include "tinyfiledialogs.h" // third-party library to upload files
#include "FileProcessor.h"
#include <chrono>

std::vector<std::string> FileProcessor::readPasswords(const std::string& fileName) {
    std::vector<std::string> passwords;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << fileName << "'." << std::endl;
        return passwords;
    }

    std::string password;
    while (std::getline(file, password)) {
        passwords.push_back(password);
    }

    file.close();
    return passwords;
}

void FileProcessor::writeToFile(const std::vector<std::string>& results, const std::string& fileName) {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << fileName << "'." << std::endl;
        return;
    }

    for (const auto& r : results) {
        file << r << std::endl;
    }

    file.close();
}

void FileProcessor::analyzePasswords()
{
    outputFileName = "password_analysis.txt";

    // Load common passwords for the validator
    const std::vector<std::string> commonPasswords = readPasswords(".\\10000_weak_passwords.txt");
    PasswordValidator validator(commonPasswords);

    // Load the user's password list
    const std::vector<std::string> userPasswords = selectFile();
    std::vector<std::string> results;

    const int totalPasswords = userPasswords.size();
    const int barWidth = 50; // Width of the progress bar

    for (size_t i = 0; i < totalPasswords; ++i) {
        const auto& p = userPasswords[i];

        // Analyze the password
        Password password;
        password.setValue(p);
        password.checkComplexity(validator);
        results.push_back("Password: " + p + "\n" + password.showUnmetRequirements());

        // Update the progress bar
        int progress = static_cast<int>((static_cast<double>(i + 1) / totalPasswords) * barWidth);
        std::cout << "\r[";
        for (int j = 0; j < barWidth; ++j) {
            if (j < progress) {
                std::cout << "#";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "] " << ((i + 1) * 100 / totalPasswords) << "%";
        std::cout.flush();
    }

    std::cout << std::endl; // Move to the next line after the progress bar
    writeToFile(results, outputFileName);
    std::cout << "Analysis results saved to '" << outputFileName << "'." << std::endl;
}


void FileProcessor::generateWeakPasswords(int count)
{
    outputFileName = "generated_weak_passwords.txt";

    // Open the output file for writing
    std::ofstream outFile(outputFileName);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << outputFileName << "' for writing." << std::endl;
        return;
    }

    const int barWidth = 50; // Width of the progress bar

    for (int i = 1; i <= count; ++i) {
        // Generate a weak password
        Password weakPassword;
        weakPassword.generateWeak(readPasswords(".\\10000_weak_passwords.txt"));
        outFile << weakPassword.getValue() << std::endl;

        // Update the progress bar
        int progress = static_cast<int>((static_cast<double>(i) / count) * barWidth);
        std::cout << "\r["; // Return to the beginning of the line
        for (int j = 0; j < barWidth; ++j) {
            if (j < progress) {
                std::cout << "#"; // Filled part of the bar
            }
            else {
                std::cout << " "; // Empty part of the bar
            }
        }
        std::cout << "] " << (i * 100 / count) << "%"; // Percentage complete
        std::cout.flush(); // Ensure the output is updated
    }

    std::cout << std::endl; // Move to the next line after the progress bar
    outFile.close();
    std::cout << "Weak passwords saved to '" << outputFileName << "'." << std::endl;
}

std::vector<std::string> FileProcessor::selectFile() {
    const char* filterPatterns[] = { "*.txt" }; // Correctly define the filter patterns

    const char* filePath = tinyfd_openFileDialog(
        "Select the passwords file",              // Title
        "",                           // Default path
        1,                            // Number of filters
        filterPatterns,               // Filter patterns
        "Text Files",                 // Filter description
        0                             // Allow multiple selection
    );

    if (filePath) {
        return this->readPasswords(filePath);
    }
    else {
        std::cerr << "No file selected." << std::endl;
        return { };
    }
}
