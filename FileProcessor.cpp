#define TINYFILEDIALOGS_IMPLEMENTATION
#include "tinyfiledialogs.h" // third-party library to upload files
#include "FileProcessor.h"

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

void FileProcessor::writePasswords(const std::vector<std::string>& passwords, const std::string& fileName) {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << fileName << "'." << std::endl;
        return;
    }

    for (const auto& password : passwords) {
        file << password << std::endl;
    }

    file.close();
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

    for (int i = 1; i <= count; ++i) {
        Password weakPassword;
        weakPassword.generateWeak();
        outFile << i << ". " << weakPassword.getValue();

    }

    outFile.close();
    std::cout << "Weak passwords saved to generated_weak_passwords.txt" << std::endl;
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
