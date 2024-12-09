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
