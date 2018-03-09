#include <stdio.h>
#include "pal.h"


void printArray(int *pListOfNumbers, int max)
{
	for (int i = 0; i < max; i++)
	{
		printf("%d", pListOfNumbers[i]);
	}
}

void displayState(int *pListOfNumbers, int cursorPosition, int maxDigits)
{
	printf("\n\nGame State: < ");
	printArray(pListOfNumbers, maxDigits);
	printf(" >\n");
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
	printf("\n");
}

void moveCursorRight(int * pCursorPosition, int max)
{
	if (*pCursorPosition < max - 1)
	{
		++ *pCursorPosition;
	}
	printf("\tTest %d:", *pCursorPosition);
}

void moveCursorLeft(int * pCursorPosition, int max)
{
	if (*pCursorPosition > 0)
	{
		-- *pCursorPosition;
	}
	printf("\tTest %d:", *pCursorPosition);
}

void incrementDigitInListAtPos(int * pListOfNumbers, int cursorPosition)
{
	pListOfNumbers[cursorPosition]++;
}