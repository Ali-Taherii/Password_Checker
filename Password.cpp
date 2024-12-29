#include "Password.h"

/**
 * Sets the value of the password if the provided string is not empty.
 *
 * @param v The new password value.
 * @return True if the password was set, false otherwise.
 */
bool Password::setValue(std::string v)
{
    if (v != "") {
        this->value = v;
        return true;
    }

    return false;
}

/**
 * Checks the complexity of the password using the provided PasswordValidator.
 * Adds unmet requirements to the unmetRequirements vector.
 *
 * @param pv The PasswordValidator to use for checking complexity.
 */
void Password::checkComplexity(PasswordValidator pv)
{
    if (!pv.checkLength(this->value))
        this->unmetRequirements.push_back("Your password is not long enough (at least 12 characters)");

    if (!pv.containsLowerCase(this->value))
        this->unmetRequirements.push_back("Your password does not have any lowercase letters");

    if (!pv.containsUpperCase(this->value))
        this->unmetRequirements.push_back("Your password does not have any uppercase letters");

    if (!pv.containsNumber(this->value))
        this->unmetRequirements.push_back("Your password does not have any numbers");

    if (!pv.containsSpecialChar(this->value))
        this->unmetRequirements.push_back("Your password does not have any special characters");

    if (!pv.isNotCommon(this->value))
        this->unmetRequirements.push_back("Your password exists in the 10000 weak passwords list");
}

/**
 * Displays the unmet complexity requirements of the password.
 * If all requirements are met, it indicates that the password meets all complexity requirements.
 */
std::string Password::showUnmetRequirements()
{
    std::string result;

    if (this->unmetRequirements.size() != 0) {
        for (std::string msg : unmetRequirements)
            result += msg + '\n';

        return result;
    }

    else
        return "Your password meets all the complexity requirements";
}

/**
 * Generates a random password that meets the complexity requirements.
 * The generated password will be at least 12 characters long and contain
 * at least one lowercase letter, one uppercase letter, one number, and one special character.
 */
void Password::generateRandom() {
    const int passwordLength = 12;

    // Character pools
    const std::string numbers = "0123456789";
    const std::string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const std::string specialCharacters = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis;

    // Ensure the password contains at least one character from each category
    value.clear();
    dis = std::uniform_int_distribution<>(0, numbers.size() - 1);
    value += numbers[dis(gen)];
    dis = std::uniform_int_distribution<>(0, upperCase.size() - 1);
    value += upperCase[dis(gen)];
    dis = std::uniform_int_distribution<>(0, lowerCase.size() - 1);
    value += lowerCase[dis(gen)];
    dis = std::uniform_int_distribution<>(0, specialCharacters.size() - 1);
    value += specialCharacters[dis(gen)];

    // Fill the rest of the password with random characters from all pools
    const std::string allCharacters = numbers + upperCase + lowerCase + specialCharacters;
    dis = std::uniform_int_distribution<>(0, allCharacters.size() - 1);
    while (value.size() < passwordLength) {
        value += allCharacters[dis(gen)];
    }

    // Shuffle the password to randomize character positions
    std::shuffle(value.begin(), value.end(), gen);
}

/**
 * Generates a weak password by randomly skipping one of the complexity rules.
 * The generated password may not meet all complexity requirements.
 */
void Password::generateWeak(const std::vector<std::string>& commonPasswords) {

    // Seed random generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 5); // Randomly choose a rule to skip
    int skipRule = dis(gen);

    std::string lower = "abcdefghijklmnopqrstuvwxyz";
    std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digits = "0123456789";
    std::string special = "!@#$%^&*()_+[]{}|;:,.<>?";
    int length;

    value.clear();

    if (skipRule == 0) { // Skip length rule
        std::uniform_int_distribution<> lenDis(6, 11);
        length = lenDis(gen);
    }
    else {
        std::uniform_int_distribution<> lenDis(12, 14);
        length = lenDis(gen);
    }

    while (value.size() < length) {
        // Fill the password based on the rules
        if (skipRule != 1) { // Include lowercase
            value += lower[dis(gen) % lower.size()];
        }
        if (skipRule != 2) { // Include uppercase
            value += upper[dis(gen) % upper.size()];
        }
        if (skipRule != 3) { // Include digits
            value += digits[dis(gen) % digits.size()];
        }
        if (skipRule != 4) { // Include special characters
            value += special[dis(gen) % special.size()];
        }
    }

    // Randomly shuffle the password
    std::shuffle(value.begin(), value.end(), gen);

    // If skipping weak list check, use a random weak password
    if (skipRule == 5 && !commonPasswords.empty()) {
        std::uniform_int_distribution<> weakDis(0, commonPasswords.size() - 1);
        value = commonPasswords[weakDis(gen)];
    }
}
