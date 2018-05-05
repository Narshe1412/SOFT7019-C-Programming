#include <stdio.h>
void incrementYear(int yearIn);
void incrementYear2(int *yearIn);
int main()
{
    void *pStack;
    asm volatile ("mov %%esp,%0;" : "=g" (pStack));
    printf("\nMain: Value of ESP register is %p", pStack);

    int year = 2018;
    printf("\nMain: value of year %d and memory %p", year, &year);
    //incrementYear(year);
    incrementYear2(&year);
    printf("\nMain: value of year %d and memory %p after function", year, &year);
    
}


void incrementYear(int yearIn)
{
    void *pStack;
    asm volatile ("mov %%esp,%0;" : "=g" (pStack));
    printf("\nIncrementYear: Value of ESP register is %p", pStack);
    printf("\nIncrementYear: Address of the year is %p value is %d", &yearIn, yearIn);    
    yearIn ++;

}

void incrementYear2(int* yearIn)
{
    void *pStack;
    asm volatile ("mov %%esp,%0;" : "=g" (pStack));
    printf("\nIncrementYear2: Value of ESP register is %p", pStack);
    printf("\nIncrementYear2: Address of the pointer to year (&) is %p value is %p and its contents (*) is %d", &yearIn, yearIn, *yearIn);    
    ++ *yearIn;

}