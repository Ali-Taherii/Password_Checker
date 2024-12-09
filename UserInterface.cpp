#include <iostream>
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
}

void UserInterface::promptUser()
{
}

void UserInterface::displayResults()
{
}
