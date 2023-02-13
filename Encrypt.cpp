/*
 * Main.cpp
 *
 *  Created on: Feb 10, 2023
 *      Author: Group 3
 */

#include <iostream>
#include <string>
#include <limits>

#include "validations.h"
#include "menuOptions.h"
#include "fileOperations.h"

using namespace std;

int main() {
	unsigned short int menuOption;

	cout << "-----ENCRYPTION APPLICATION-----" << endl;

	menuOption = promptMenuOption();

	while (menuOption != 0) {
		switch (menuOption) {
			case 1:
				encryptPasswords();
				break;
			default:
				cout << "Input is not a recognized command." << endl;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the entire input stream
				break;
		}

		menuOption = promptMenuOption();
	}

	cout << "Exiting ENCRYTPTION APPLICATION" << endl;

	return 0;
}

