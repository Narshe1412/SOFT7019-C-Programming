#include <stdio.h>

int main() 
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        printf("Letter %2c %d %#x\n", i, i, i);
    };
    for (int i = 'a'; i <= 'z'; i++)
    {
        printf("Letter %2c %d %#x\n", i, i, i);
    };
    
    return 0;
}