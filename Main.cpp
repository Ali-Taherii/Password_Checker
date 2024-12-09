#include <iostream>
#include "Password.h"
#include "FileProcessor.h"
#include "PasswordValidator.h"
#include "UserInterface.h"

using namespace std;

int main() {
	FileProcessor fileProcessor;

	// Step 1: Load common passwords using FileProcessor
	const std::vector<std::string> commonPasswords = fileProcessor.readPasswords(".\\10000_weak_passwords.txt");

	// Step 2: Pass common passwords to PasswordValidator
	PasswordValidator validator(commonPasswords);

	UserInterface ui;
	int choice;

	do {
		ui.displayMenu();
		choice = ui.promptUser();

		switch (choice) {
		case 1: {
			ui.displayResults("You chose to check password complexity.");
			// Add logic for password complexity checking
			break;
		}
		case 2: {
			ui.displayResults("You chose to generate a random password.");
			Password password;
			password.generateRandom();
			std::cout << "Generated Password: " << password.getValue() << std::endl;
			break;
		}
		case 3:
			ui.displayResults("You chose to check a list of passwords.");
			// Add logic for file password analysis
			break;
		case 4:
			ui.displayResults("You chose to generate weak passwords.");
			// Add logic for weak password generation
			break;
		case 5:
			ui.displayResults("This program checks and generates passwords based on secure coding practices.");
			break;
		case 6:
			ui.displayResults("Exiting the program. Goodbye!");
			break;
		}
	} while (choice != 6);


	return 0;
}