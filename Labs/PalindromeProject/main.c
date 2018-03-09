#include <stdio.h>
#include <stdlib.h>
#include "pal.h"
#include "useful.h"

void startGame(int initialNumber)
{
	//int listOfNumbers[] = { 1,2,3,6,8,9 };
	//int numberOfDigits = 6;

	int numberOfDigits;
	int * listOfNumbers = initialiseArray(initialNumber, &numberOfDigits);
	int cursorPosition = getRandomStart(numberOfDigits);
	int numberOfGoes = 0;

	printf("Welcome to the palider...patid...polyg.... Palindrome game!");
	displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

	while (!isPalindrome(listOfNumbers, numberOfDigits))
	{
		processCommand(listOfNumbers, numberOfDigits, &cursorPosition, getCommand(), &numberOfGoes);
		displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
	}

	printf("\nYou won The Game! \nThe total number of attempts is: %d", numberOfGoes);

	free(listOfNumbers);
}

int main()
{
	int initialNumber = 1236719;
	startGame(initialNumber);

	return 0;
}
