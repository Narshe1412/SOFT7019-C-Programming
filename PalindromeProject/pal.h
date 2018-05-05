#include "useful.h"
#ifndef _PAL_H_
#define _PAL_H_

void displayState(int * pListOfNumbers, int cursorPosition, int maxDigits, int numberOfGoes);
boolean isPalindrome(int * pListOfNumbers, int size);
char getCommand();
void processCommand(int * pList, int size, int * pCursorPosition, char command, int * numberOfGoes);
int * initialiseArray(int initialNumber, int * size);
int getRandomPos(int size);
int getRandomNumber(int minSize);

#endif