#include "Password.h"

bool Password::isValid()
{
	return false;
}

std::vector<std::string> Password::unmetRequirements()
{
	return std::vector<std::string>();
}


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


