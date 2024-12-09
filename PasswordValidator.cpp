#include "PasswordValidator.h"

bool PasswordValidator::checkLength(const std::string& password)
{
    return password.length() >= 12;
}

bool PasswordValidator::containsSpecialChar(const std::string& password) {
    // The set of special characters
    const std::string SPECIAL_CHARACTERS = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    return std::any_of(password.begin(), password.end(), [&](char c) {
        return SPECIAL_CHARACTERS.find(c) != std::string::npos;
        });
}

bool PasswordValidator::containsUpperCase(const std::string& password) {
    return std::any_of(password.begin(), password.end(), ::isupper);
}

bool PasswordValidator::containsLowerCase(const std::string& password)
{
    return std::any_of(password.begin(), password.end(), ::islower);
}

bool PasswordValidator::containsNumber(const std::string& password)
{
    return std::any_of(password.begin(), password.end(), ::isdigit);
}

bool PasswordValidator::isNotCommon(const std::string& password) {
    
    static std::unordered_set<std::string> commonPasswords;
    if (commonPasswords.empty()) {
        std::ifstream file("C:\\Users\\alita\\Downloads\\10-million-password-list-top-100.txt"); // Load the weak passwords list
        std::string commonPassword;
        while (std::getline(file, commonPassword)) {
            commonPasswords.insert(commonPassword);
        }
    }

    return commonPasswords.find(password) == commonPasswords.end();
}