/*
 * optionsMenu.cpp
 *
 *  Created on: Apr 13, 2025
 *      Author: willc
 */

#include <stdio.h>
#include "optionsMenu.h"
#include "mainMenu.h"

MainMenu menu; // Create an instance of the MainMenu class

void OptionsMenu::displayOptions(){
	printf("Game Options\n");
	printf("1. Sound\n");
	printf("2. Graphics\n");
	printf("3. Controls\n");
	printf("4. Back to Main Menu\n");
	
	int choice;
	printf("Choice: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("Adjusting sound settings...\n");
			break;
		case 2:
			printf("Adjusting graphics settings...\n");
			break;
		case 3:
			printf("Adjusting control settings...\n");
			break;
		case 4:
			printf("Returning to main menu...\n");
			menu.displayMenu(); // Display the menu
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
	}
}