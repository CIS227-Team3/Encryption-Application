/*
 * menuOptions.cpp
 *
 *  Created on: Feb 11, 2023
 *      Author: Group 3
 */


#include "menuOptions.h"

void printAndClearError() {
	cout << "Input must be a positive integer." << endl;

	cin.clear(); // clears error flag from input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire input stream
}

unsigned short int promptMenuOption() {
	unsigned short int menuOption;

		cout << "Please enter one of the following menu options: " << endl;
		cout << "1. Encrypt a new file." << endl;
		cout << "0. Exit." << endl;

		menuOption = validateMenuOption();

	return menuOption;
}
