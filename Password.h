#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "PasswordValidator.h"

class Password {

private: 
	std::string value;
	std::vector<std::string> unmetRequirments;

public:
	bool setValue(std::string v);
	const std::string& getValue() const { return value; } // Getter for the password
	void checkComplexity(PasswordValidator pv);
	void showUnmetRequirements();
	void generateRandom(); // Generate a random password
};

#endif // !PASSWORD_H