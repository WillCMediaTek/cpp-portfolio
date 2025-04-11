/*
 * mainMenu.cpp
 *
 *  Created on: Apr 11, 2025
 *      Author: Willie Clifton
 */

#include <stdio.h>
#include "mainMenu.h"
#include "tutorial.h"	
	
// Unlike creating a class in the main file, this source file is used to implement the  MainMenu class 
	
// Function to display the menu
void MainMenu::displayMenu(){
	printf("Game Menu\n");
	printf("1. New Game\n");
	printf("2. Load Game\n");
	printf("3. Options\n");
}
		
// Function to get user input and handle menu selection
void MainMenu::getUserInput(){
	int choice;
	printf("Choice: ");
	scanf("%d", &choice);
		
	switch(choice){
		case 1:
			printf("Starting a new game\n");
			displayTutorial(); // Call the tutorial function
			break;
		case 2:
			printf("Select a save to load\n");
			break;
		case 3:
			printf("Game Options \n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
	}
}


