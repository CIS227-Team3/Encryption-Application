/*
 * validations.cpp
 *
 *  Created on: Feb 11, 2023
 *      Author: Group 3
 */

#include "menuOptions.h"

unsigned short  int validateMenuOption() {
	unsigned short int input;
	    while(true){
	        if (std::cin >> input) { // if the user entered an integer
	        	cin.ignore(1000, '\n');
	            return input;
	        } else {
	            printAndClearError();
	        }
	    }
}


