#ifndef _PAL_H_
#define _PAL_H_


void displayState(int * pListOfNumbers, int cursorPosition, int maxDigits);

void moveCursorRight(int * pCursorPosition, int max);

void moveCursorLeft(int * pCursorPosition, int max);

void incrementDigitInListAtPos(int * pListOfNumbers, int cursorPosition);

#endif