#include <stdio.h>

int main()
{
    int num1, num2;
    char name[10];
    char surname[10];
    printf("\nPlease enter first number: ");
    scanf("%d", &num1);
    printf("Please enter second number: ");
    scanf("%d", &num2);
    printf("Now your name: ");
    scanf("%9s", name);
    printf("And your surname: ");
    scanf("%9s", surname);
    printf("\nYour name is %s %s, and your numbers are %d and %d", name, surname, num1, num2);
}
