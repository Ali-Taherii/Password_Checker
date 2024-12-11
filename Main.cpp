#include <iostream>
#include "Password.h"
#include "FileProcessor.h"
#include "UserInterface.h"

using namespace std;

int main() {
	FileProcessor fileProcessor;
	UserInterface ui;
	int choice;

	do {
		ui.displayMenu();
		ui.promptUser("menu", choice);

		switch (choice) {
		case 1: {
			ui.displayResults("You chose to check password complexity.");
			string password_value;
			if (ui.promptUser("password", password_value)) {
				cout << "Your password: " << password_value << endl;

				const vector<string> commonPasswords = fileProcessor.readPasswords(".\\10000_weak_passwords.txt");
				PasswordValidator validator(commonPasswords);

				Password password;
				password.setValue(password_value);
				password.checkComplexity(validator);
				password.showUnmetRequirements();
			}
			break;
		}
		case 2: {
			ui.displayResults("You chose to generate a random password.");
			Password password;
			password.generateRandom();
			std::cout << "Generated Password: " << password.getValue() << std::endl;
			break;
		}
		case 3: {
			ui.displayResults("You chose to check a list of passwords.");

			// Load common passwords for the validator
			const vector<string> commonPasswords = fileProcessor.readPasswords(".\\10000_weak_passwords.txt");
			PasswordValidator validator(commonPasswords);

			// Load the user's passowrd list
			const vector<string> userPasswords = fileProcessor.selectFile();

			for (string p : userPasswords) {
				Password password;
				password.setValue(p);
				cout << "Password: " << p << endl;
				password.checkComplexity(validator);
				password.showUnmetRequirements();
				cout << endl;
			}

			break;
		}
		case 4: {
			ui.displayResults("You chose to generate weak passwords.");
			int passNum;
			ui.promptUser("weak_password", passNum);
			fileProcessor.generateWeakPasswords(passNum);
			break;
		}
		case 5: {
			ui.displayResults("This program checks and generates passwords based on secure coding practices.");
			break;
		}
		case 6:
			ui.displayResults("Exiting the program. Goodbye!");
			break;
		}
	} while (choice != 6);


	return 0;
}