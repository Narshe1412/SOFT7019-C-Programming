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

    if (firstLetter >= 'a' && firstLetter <= 'z')
        firstLetter -= 32;
    if (secondLetter >= 'a' && secondLetter <= 'z')
        secondLetter -= 32;
    printf ("\nInitials uppercase are %c.%c.", firstLetter, secondLetter);

    return 0;
}
