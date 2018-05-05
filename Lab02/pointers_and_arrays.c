#include <stdio.h>

int main()
{
    char * pLetter = NULL;
    char letters[] = {'w', 'x', 'y', 'z'};
    int i = 0;
    pLetter = &letters[0];
    while(i < 4) 
    {
        printf("\nAddress of pointer = %p ", pLetter);
        printf("Value of pLetter = %c", *pLetter);
        i++;
        pLetter++;
    }

    int * pNum = NULL;
    int numbers[] = {1,2,3,4};
    i = 0;
    pNum = &numbers[0];
    while(i<4)
    {
        printf("\nAddress of pointer = %p  Value of pointer = %d", pNum, *pNum);
        i++;
        pNum++;
    }

    pNum = numbers;
    printf("\n\nValue of pNum = numbers: %p", pNum);
    pNum = &numbers[0];
    printf("\nValue of pNum = &numbers[0]: %p", pNum);
    pNum = pNum + 1;
    printf("\nValue of pNum = pNum + 1: %p", pNum);
    
    i = 0;
    pNum = numbers;
    while(i<4)
    {
        printf("\nAddress of pointer = %p  Value of pointer = %d", pNum, *pNum);
        i++;
        pNum++;
    }
}
