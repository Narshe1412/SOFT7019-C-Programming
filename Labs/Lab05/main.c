#include <stdio.h>
#include "pal.h"
#include "useful.h"

void startGame()
{
	int listOfNumbers[] = { 1,2,3,6,8,9 };
	int numberOfDigits = 6;
	int cursorPosition = 0;
	int numberOfGoes = 0;

	printf("Welcome to the palider...patid...polyg.... Palindrome game!");
	displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

	while (!isPalindrome(listOfNumbers, numberOfDigits))
	{
		numberOfGoes++;
		processCommand(listOfNumbers, numberOfDigits, &cursorPosition, getCommand());
		displayState(listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
	}

	printf("\nYou won The Game! \nThe total number of attempts is: %d", numberOfGoes);
	getchar();

}

int main()
{
	startGame();

	return 0;
}
