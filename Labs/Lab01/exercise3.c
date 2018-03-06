#include <stdio.h>

int main() 
{
    int firstLetter;
    int secondLetter;
    printf("\nPlease enter your first initial and press enter: ");
    firstLetter = getchar();
    getchar();

    printf("\nPlease enter your first initial and press enter: ");
    secondLetter = getchar();
    getchar();
    putchar(firstLetter);
    putchar('.');
    putchar(secondLetter);
    putchar('.');
    
    printf("\n+1 to the chars: ");
    firstLetter++;
    secondLetter++;
    printf("%c.%c.", firstLetter, secondLetter);

    getchar();
    return 0;
}