#include <stdio.h>
#include <stdlib.h>
#include "pal.h"
#include "useful.h"

void startGame(int initialNumber)
{
	/*Initialize game state*/
	int numberOfDigits;
	int * listOfNumbers = initialiseArray(initialNumber, &numberOfDigits);
	int cursorPosition = getRandomPos(numberOfDigits);
	int numberOfGoes = 0;

	/*Welcome message and initial state*/
	printf("Welcome to the palider...patid...polyg.... Palindrome game!");
	displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

	/*While the number is NOT a palindrome, ask for a new command*/
	while (!isPalindrome(listOfNumbers, numberOfDigits))
	{
		/*Process a command and display state again*/
		processCommand(listOfNumbers, numberOfDigits, &cursorPosition, getCommand(), &numberOfGoes);
		displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
	}

	/*After the number is a palindrome, end the game showing the number of steps taken*/
	printf("\nYou won The Game! \nThe total number of attempts is: %d", numberOfGoes);

	/*Free allocs during the program*/
	free(listOfNumbers);
}

int main()
{
	/*Get a random number and start the game with it*/
	int initialNumber = getRandomNumber(6);
	startGame(initialNumber);
	
	return 0;
}
