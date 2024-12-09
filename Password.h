#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>

class Password {

private: 
	std::string value;

public:
	bool isValid();
	std::vector<std::string> unmetRequirements();
	void generateRandom(); // Generate a random password
	const std::string& getValue() const { return value; } // Getter for the password
};

#endif // !PASSWORD_H