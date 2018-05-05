#include <stdio.h>
#include "pal.h"
#include "useful.h"
#include <string.h>

void printArray(int *pListOfNumbers, int max)
{
	for (int i = 0; i < max; i++)
	{
		printf("%d", pListOfNumbers[i]);
	}
}

/*
void testPalindrome() {

	int test1[] = { 1,2,3,3,2,1 };
	printf("\nThe array ");
	printArray(test1, 6);
	printf(" is %d", isPalindrome(test1, 6));
	int test2[] = { 1,2,3,3,2,2 };
	printf("\nThe array ");
	printArray(test2, 6);
	printf(" is %d", isPalindrome(test2, 6));
	int test3[] = { 1,2,3,1,2,1 };
	printf("\nThe array ");
	printArray(test3, 6);
	printf(" is %d", isPalindrome(test3, 6));
	int test4[] = { 1,2,3,1,3,3 };
	printf("\nThe array ");
	printArray(test4, 6);
	printf(" is %d", isPalindrome(test4, 6));

}
*/

void displayState(int *pListOfNumbers, int cursorPosition, int maxDigits, int numberOfGoes)
{
	printf("\n\nGame State: < ");
	printArray(pListOfNumbers, maxDigits);
	printf(" >  Number of Goes: %d \n", numberOfGoes);
	printf("              "); /* Trailing spaces for cursor position*/
	for (int x = 0; x < maxDigits; x++)
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

void moveCursorRight(int * pCursorPosition, int max)
{
	if (*pCursorPosition < max - 1)
	{
		++ *pCursorPosition;
	}
}

void moveCursorLeft(int * pCursorPosition, int max)
{
	if (*pCursorPosition > 0)
	{
		-- *pCursorPosition;
	}
}

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

boolean isPalindrome(int * pListOfNumbers, int size)
{
	boolean result = True;
	for (int i = 0; i < size / 2; i++)
	{
		if (pListOfNumbers[i] != pListOfNumbers[size - i - 1])
			result = False;
	}
	return result;
}

char getCommand()
{
	char command;
	boolean isValid = False;
	char validCharacters[] = {'a','d','w','x'};
	while (!isValid)
	{
		printf("\nPlease enter a new command: [a d w x] ");
		command = myGetChar();
		if (strchr(validCharacters, command))
			isValid = True;
		else
			printf("Incorrect command. Must be a single letter [a d w x] ");
	}
	return command;
}

void processCommand(int *pList, int size, int *pCursorPosition, char command)
{
	switch (command)
	{
	case 'a':
		moveCursorLeft(pCursorPosition, size);
		break;
	case 'd':
		moveCursorRight(pCursorPosition, size);
		break;
	case 'w':
		incrementDigitInListAtPos(pList, *pCursorPosition);
		break;
	case 'x':
		decrementDigitInListAtPos(pList, *pCursorPosition);
		break;
	}
}