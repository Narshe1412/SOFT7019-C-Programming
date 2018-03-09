#include <stdio.h>
#include "pal.h"
#include "useful.h"

void printArray(int *pListOfNumbers, int max)
{
	for (int i = 0; i < max; i++)
	{
		printf("%d", pListOfNumbers[i]);
	}
}

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

void displayState(int *pListOfNumbers, int cursorPosition, int maxDigits, int numberOfGoes)
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
	printf("\nNumber of Goes: %d\n", numberOfGoes);
	testPalindrome();
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