#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>

class UserInterface {
	
public:
	UserInterface();
	void displayMenu();

	template <typename T>
	bool promptUser(const std::string& requestType, T& value);
	
	void displayResults(const std::string& result);
	
};

#endif // !USERINTERFACE_H

template<typename T>
inline bool UserInterface::promptUser(const std::string& requestType, T& value)
{
	if (requestType == "menu") {
		int choice;
		std::cout << "Enter your choice (1-6): ";
		while (!(std::cin >> choice) || choice < 1 || choice > 6) {
			std::cout << "Invalid input. Please enter a number between 1 and 6: ";
			std::cin.clear(); // Clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
		}

		// Assign value without casting
		if constexpr (std::is_same_v<T, int>) {
			value = choice; // Compatible type (int)
			return true;
		}
		else {
			std::cerr << "Error: 'menu' request requires an integer type." << std::endl;
			return false;
		}
	}
	else if (requestType == "password") {
		std::string password;
		std::cout << "Enter your password: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline
		std::getline(std::cin, password); // Get the full input

		// Assign value without casting
		if constexpr (std::is_same_v<T, std::string>) {
			value = password; // Compatible type (std::string)
			return true;
		}
		else {
			std::cerr << "Error: 'password' request requires a string type." << std::endl;
			return false;
		}
	}
	else if(requestType == "weak_password") {
		int num;
		std::cout << "Enter the number of passwords to be generated: ";
		std::cin >> num;

		// Assign value without casting
		if constexpr (std::is_same_v<T, int>) {
			value = num;
			return true;
		}
		else {
			std::cerr << "Error: 'weak_password' request requires an integer type." << std::endl;
			return false;
		}
	}
	else {
		std::cerr << "Invalid request type: " << requestType << std::endl;
		return false;
	}
}
