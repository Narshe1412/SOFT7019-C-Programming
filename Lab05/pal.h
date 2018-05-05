#ifndef _PAL_H_
#define _PAL_H_


void displayState(int * pListOfNumbers, int cursorPosition, int maxDigits, int numberOfGoes);

void moveCursorRight(int * pCursorPosition, int max);

void moveCursorLeft(int * pCursorPosition, int max);

void incrementDigitInListAtPos(int * pListOfNumbers, int cursorPosition);

void decrementDigitInListAtPos(int * pListOfNumbers, int cursorPosition);

isPalindrome(int * pListOfNumbers, int size);

char getCommand();

void processCommand(int * pList, int size, int * pCursorPosition, char command);

#endif