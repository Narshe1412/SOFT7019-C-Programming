#include <stdio.h>

int main() 
{
    char alphabetLetters[26];
    for (int i = 0; i < 26; i++)
    {
        alphabetLetters[i] = i + 'a';
    };
    alphabetLetters[26] = 0;
    printf("Array: %s", alphabetLetters);
}