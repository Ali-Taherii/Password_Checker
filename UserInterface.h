#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>

class UserInterface {
	
public:
	UserInterface();
	void displayMenu();
	int promptUser();
	void displayResults(const std::string& result);
	
};

#endif // !USERINTERFACE_H