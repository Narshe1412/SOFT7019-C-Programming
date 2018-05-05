#include <stdio.h>

int main()
{
    printf("Please enter your name: ");
    char name[10];
    scanf("%9s", name);
    printf("Result: %s", name);
}