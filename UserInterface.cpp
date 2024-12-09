#include "UserInterface.h"

UserInterface::UserInterface() {
	std::cout << "Welcome to PASSWORD CHECKER" << std::endl;
}

void UserInterface::displayMenu()
{
	std::cout << "\n============ MENU ============" << std::endl;
	std::cout << "1. Check your password complexity" << std::endl;
	std::cout << "2. Generate a random complex password" << std::endl;
	std::cout << "3. Check a list of passwords for complexity" << std::endl;
	std::cout << "4. Generate a list of weak passwords" << std::endl;
	std::cout << "5. Explain how the program works" << std::endl;
	std::cout << "6. Exit" << std::endl;
}

int UserInterface::promptUser() {
	int choice;
	std::cout << "Enter your choice (1-6): ";
	while (!(std::cin >> choice) || choice < 1 || choice > 6) {
		std::cout << "Invalid input. Please enter a number between 1 and 6: ";
		std::cin.clear();  // Clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
	}
	return choice;
}

void UserInterface::displayResults(const std::string& result) {
	std::cout << "\n===== Result =====" << std::endl;
	std::cout << result << std::endl;
}
