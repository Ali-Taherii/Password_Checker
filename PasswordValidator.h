#pragma once
#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <iostream>
#include <cctype>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_set>

class PasswordValidator {

private:
	std::unordered_set<std::string> commonPasswords;

public:
	PasswordValidator(const std::vector<std::string>& commonPasswordsList);
	bool checkLength(const std::string& password);
	bool containsNumber(const std::string& password);
	bool containsSpecialChar(const std::string& password);
	bool containsUpperCase(const std::string& password);
	bool containsLowerCase(const std::string& password);
	bool isNotCommon(const std::string& password);
};

#endif // !PASSWORDVALIDATOR_H