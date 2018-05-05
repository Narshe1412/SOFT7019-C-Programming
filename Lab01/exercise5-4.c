#include <stdio.h>

int main() 
{   
    int number = -1;
    int operand1 = 0;
    int operand2 = 0;

    while (number < 1 || number > 10) 
    {
        printf("\nPlease enter a number from 1 to 10: ");
        char key = getchar();
        number = key - '0';
        if (number < 1 || number > 10) 
        {
            printf("\nIncorrect number.");
            getchar();
        } 
        else if (!operand1) 
        {
            operand1 = number;
            number = -1;
            getchar();
        } 
        else 
        {
            operand2 = number;
        }
        
    }
    printf("Solution: %d", operand1 + operand2);
}