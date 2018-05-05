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

    char initials[5];
    initials[0]= firstLetter;
    initials[1]='.';
    initials[2]=secondLetter;
    initials[3]='.';
    initials[4]='\0';

    printf("\nInitials array are %s", initials);

    char word[4];
    word[0] = 'c';
    word[1] = 'a';
    word[2] = 't';
    printf("\nWord array is %s", word);
    word[3] = '\0';
    printf("\nFixed Word array is %s", word);

    char shortword[2];
    shortword[0] = 'c';
    shortword[1] = 'a';
    shortword[2] = 't';
    shortword[3] = '\0';
    printf("\nShort Word array is %s", shortword);

    
    getchar();
    return 0;
};