#include <stdio.h>
#include <stdlib.h>

void multiplyBytwo(int *num);
int main() 
{
    int value = 77;
    multiplyBytwo(&value);
    printf("\nMain: multiplied = %d", value );
}

void multiplyBytwo(int *num)
{
    printf("\nFunc: number value = %d", *num);
    *num = *num * 2;
}