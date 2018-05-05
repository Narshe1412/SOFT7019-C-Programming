#include <stdio.h>
#include "pal.h"

int main()
{
	int listOfNumbers[] = { 1,2,3,6,8,9 };
	int numberOfDigits = 6;
	int cursorPosition = 0;

	printf("\nAddress location of array is %p", listOfNumbers);
	printf("\nPosition of cursor is %d", cursorPosition);

	displayState(listOfNumbers, cursorPosition, numberOfDigits);

	//Test Cursor Movement

	moveCursorRight(&cursorPosition, numberOfDigits);
	displayState(listOfNumbers, cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorLeft(&cursorPosition, numberOfDigits);
	moveCursorLeft(&cursorPosition, numberOfDigits);
	moveCursorLeft(&cursorPosition, numberOfDigits);
	moveCursorLeft(&cursorPosition, numberOfDigits);
	displayState(listOfNumbers, cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	moveCursorRight(&cursorPosition, numberOfDigits);
	displayState(listOfNumbers, cursorPosition, numberOfDigits);

	//Test increment digit
	incrementDigitInListAtPos(listOfNumbers, 1);
	incrementDigitInListAtPos(listOfNumbers, 1);
	incrementDigitInListAtPos(listOfNumbers, 1);
	incrementDigitInListAtPos(listOfNumbers, 1);
	incrementDigitInListAtPos(listOfNumbers, 1);
	incrementDigitInListAtPos(listOfNumbers, 3);
	incrementDigitInListAtPos(listOfNumbers, 3);
	incrementDigitInListAtPos(listOfNumbers, 0);
	incrementDigitInListAtPos(listOfNumbers, 2);
	incrementDigitInListAtPos(listOfNumbers, 5);

	displayState(listOfNumbers, cursorPosition, numberOfDigits);

	getchar();
}

