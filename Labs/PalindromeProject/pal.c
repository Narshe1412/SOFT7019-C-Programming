#include <stdio.h>
#include <stdlib.h>
#include "pal.h"
#include "useful.h"
#include <string.h>
#include <math.h>
#include <time.h>

/*Prints array of numbers on the screen*/
void printArray(int *pListOfNumbers, int max)
{
	for (int i = 0; i < max; i++)
	{
		printf("%d", pListOfNumbers[i]);
	}
}

/*Displays the state of the game at any given time*/
void displayState(int *pListOfNumbers, int cursorPosition, int maxDigits, int numberOfGoes)
{
	/*
	Line formatted as:
		"Game state: <##########>  Number of Goes: 43"
					     ^ 
	*/
	printf("\n\nGame State: < ");
	printArray(pListOfNumbers, maxDigits);
	printf(" >  Number of Goes: %d \n", numberOfGoes);
	printf("              "); /* Trailing spaces for cursor position*/
	for (int x = 0; x < maxDigits; x++) /*Loop to draw the cursor at given position*/
	{
		if (x == cursorPosition)
		{
			printf("^");
		}
		else
		{
			printf(" ");
		}
	}
}

/*This function moves the cursor to the right, unless it's at the rightmost position
Returns true if the movement happened, false otherwise*/
boolean moveCursorRight(int * pCursorPosition, int max)
{
	if (*pCursorPosition < max - 1) 
	{
		++ *pCursorPosition;
		return True;
	}
	return False;
}

/*This function moves the cursor to the left, unless it's at the leftmost position
Returns true if the movement happened, false otherwise*/
boolean moveCursorLeft(int * pCursorPosition, int max)
{
	if (*pCursorPosition > 0)
	{
		-- *pCursorPosition;
		return True;
	}
	return False;
}

/*Increments a digit at a given position. If the digit is at maximum (9) it rolls over 0 again.*/
void incrementDigitInListAtPos(int * pListOfNumbers, int cursorPosition)
{
	if (pListOfNumbers[cursorPosition] >= 9)
	{
		pListOfNumbers[cursorPosition] = 0;
	}
	else
	{
		pListOfNumbers[cursorPosition]++;
	}
}

/*Decrements a digit at a given position. If the digit is at minimum (0) it rolls over 9 again.*/
void decrementDigitInListAtPos(int * pListOfNumbers, int cursorPosition)
{
	if (pListOfNumbers[cursorPosition] <= 0)
	{
		pListOfNumbers[cursorPosition] = 9;
	}
	else
	{
		pListOfNumbers[cursorPosition]--;
	}
}

/*Calculate if the array is palindrome returning true or false depending on the state of the array*/
boolean isPalindrome(int * pListOfNumbers, int size)
{
	boolean result = True;
	/*We transverse half of the array and check the position and position-i if they match.
	  As soon as we found a mismatch, return false. Otherwise return true.*/
	for (int i = 0; i < size / 2; i++)
	{
		if (pListOfNumbers[i] != pListOfNumbers[size - i - 1])
			result = False;
	}
	return result;
}

/*Get command from input stream. Returns a valid command only, otherwise it keeps asking.*/
char getCommand()
{
	char command;
	boolean isValid = False;
	char validCharacters[] = { 'a','d','w','x' };
	while (!isValid)
	{
		printf("\nPlease enter a new command: [a d w x] ");
		command = myGetChar();
		if (strchr(validCharacters, command)) /*Check if command is valid by verifying it matches the array contents*/
			isValid = True;
		else
			printf("Incorrect command. Must be a single letter [a d w x] ");
	}
	return command;
}

/*Process a command input and add increments a go if the command is valid
Valid command is Increment or Decrement always, and Move only if it actually moves the cursor (returns true)*/
void processCommand(int *pList, int size, int *pCursorPosition, char command, int * pNumberOfGoes)
{
	switch (command)
	{
	case 'a':
		if (moveCursorLeft(pCursorPosition, size))
			++*pNumberOfGoes;
		break;
	case 'd':
		if (moveCursorRight(pCursorPosition, size))
			++*pNumberOfGoes;
		break;
	case 'w':
		incrementDigitInListAtPos(pList, *pCursorPosition);
		++*pNumberOfGoes;
		break;
	case 'x':
		decrementDigitInListAtPos(pList, *pCursorPosition);
		++*pNumberOfGoes;
		break;
	}
}

/*Initialise an array based on a random number of random size
Size is passed by pointer to return the value*/
int * initialiseArray(int initialNumber, int * size)
{
	/*Calculate the number of digits by doing log10 on the number plus 1*/
	int arrayLength = (int)floor(log10(initialNumber)) + 1; 
	/*Allocates memory for an array of X positions, based on the number of digits*/
	int * numArray = (int *)malloc(arrayLength * sizeof(int)); 
	/*
	Transverse the array we created adding each digit to the array. This is done by calculating the remainder of a division
	by 10, and adding it at the last empty position of the array. Keep going until the array is completely filled.
	*/
	for (int x = arrayLength - 1; x >= 0; x--) {
		numArray[x] = initialNumber % 10;
		initialNumber /= 10;
	}
	/*Return size value (passed as pointer)*/
	*size = arrayLength;
	/*Return complete array*/
	return numArray;
}

/*Get random position for the cursor using a random seed using time()*/
int getRandomPos(int size)
{
	srand((unsigned int) time(NULL));
	return rand() % size;
}

/*Generates a random number using a random seed, making sure it's big enough and complies with the minimum size*/
int getRandomNumber(int minSize)
{
	srand((unsigned int)time(NULL));
	int randomizer = rand();
	return (randomizer * randomizer) + (minSize * 10);
}