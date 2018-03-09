#include <stdio.h>
#include "pal.h"
#include "useful.h"

int main()
{
	int listOfNumbers[] = { 1,2,3,6,8,9 };
	int numberOfDigits = 6;
	int cursorPosition = 0;
	int numberOfGoes = 0;

	printf("\nAddress location of array is %p", listOfNumbers);
	printf("\nPosition of cursor is %d", cursorPosition);

	displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);


	while (1)
	{
		processCommand(listOfNumbers, numberOfDigits, &cursorPosition, getCommand());	
		displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
	}

	getchar();
}

