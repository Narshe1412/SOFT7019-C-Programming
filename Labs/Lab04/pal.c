#include <stdio.h>

void displayState(int *pListOfNumbers, int cursorPosition, int maxDigits) 
{
    printf("\n\nGame State: < ");
    for (int i = 0; i < maxDigits; i++)
    {
        printf("%d", pListOfNumbers[i]);
    }
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
