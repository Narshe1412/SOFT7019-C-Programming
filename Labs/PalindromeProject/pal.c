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

boolean moveCursorRight(int * pCursorPosition, int max)
{
	if (*pCursorPosition < max - 1)
	{
		++ *pCursorPosition;
		return True;
	}
	return False;
}

boolean moveCursorLeft(int * pCursorPosition, int max)
{
	if (*pCursorPosition > 0)
	{
		-- *pCursorPosition;
		return True;
	}
	return False;
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

initialiseArray(int initialNumber) 
{

}