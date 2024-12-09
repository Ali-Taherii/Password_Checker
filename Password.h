#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <vector>

class Password {

private: 
	std::string value;

public:
	bool isValid();
	std::vector<std::string> unmetRequirements();
	void generateRandom();
};

#endif // !PASSWORD_H