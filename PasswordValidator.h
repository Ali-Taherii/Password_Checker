#pragma once
#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <string>

class PasswordValidator {

public:
	bool checkLength(const std::string& password);
	bool containsNumber(const std::string& password);
	bool containsSpecialChar(const std::string& password);
	bool containsUpperCase(const std::string& password);
	bool containsLowerCase(const std::string& password);
	bool isNotCommon(const std::string& password);
};

#endif // !PASSWORDVALIDATOR_H