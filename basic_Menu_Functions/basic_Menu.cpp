/*
 * basic_Menu.cpp
 *
 *  Created on: Apr 10, 2025
 *      Author: Willie Clifton
 */

// FNK Software Solutions
// This program demonstrates the C++ implementation of a basic menu system

#include <stdio.h>

#include "mainMenu.h"

int main(){
	MainMenu menu; // Create an instance of the MainMenu class
	menu.displayMenu(); // Display the menu

	getchar();		
	return 0;
}