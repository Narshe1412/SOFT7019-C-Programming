#include <stdio.h>
#include "pal.h"

int main()
{
    int listOfNumbers[] = {1,2,3,6,8,9};
    int numberOfDigits = 6;
    int cursorPosition = 0;

    printf("\nAddress location of array is %p", listOfNumbers);
    printf("\nPosition of cursor is %d", cursorPosition);

    displayState(listOfNumbers, cursorPosition, numberOfDigits);

	getchar();
}

