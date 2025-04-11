/*
 * basic_Menu.cpp
 *
 *  Created on: Apr 10, 2025
 *      Author: Willie Clifton
 */

// FNK Software Solutions
// This program demonstrates the C++ implementation of a basic menu system

#include <stdio.h>

int main(){
	printf("Game Menu\n");
	printf("1, New Game\n");
	printf("2. Load Game\n");
	printf("3. Options\n");
	
	int choice;
	printf("Choice: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("Starting a new game\n");
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
	getchar();		
	return 0;
}