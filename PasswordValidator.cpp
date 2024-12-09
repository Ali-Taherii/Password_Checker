#include "PasswordValidator.h"

PasswordValidator::PasswordValidator(const std::vector<std::string>& commonPasswordsList) {
    for (const auto& password : commonPasswordsList) {
        commonPasswords.insert(password);
    }
}

bool PasswordValidator::checkLength(const std::string& password) {
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

bool PasswordValidator::containsLowerCase(const std::string& password) {
    return std::any_of(password.begin(), password.end(), ::islower);
}

bool PasswordValidator::containsNumber(const std::string& password) {
    return std::any_of(password.begin(), password.end(), ::isdigit);
}

bool PasswordValidator::isNotCommon(const std::string& password) {

    if (!commonPasswords.empty()) {

        // Check if the password exists in the set
        for (std::string p : commonPasswords) {
            if (password == p)
                return true;
        }

        return false;
    } 
    else {
        std::cout << "The list of common passwords was not loaded" << std::endl;
    }
}