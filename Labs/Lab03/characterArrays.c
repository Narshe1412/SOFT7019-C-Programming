#include <stdio.h>
#include <string.h>

int main()
{
    #define MAX 5

    char word1[] = {'h','e','l','l','o','\0'};
    char word2[] = "World";
    char word3[] = {'h','i','\0','x','o','c', 'w','y'};

    printf("\nSize of word1 %d", sizeof(word1));
    printf("\nSize of word2 %d", sizeof(word2));
    printf("\nSize of word3 %d", sizeof(word3));
    
    printf("\nWord1 is %s", word1);
    printf("\nWord2 is %s", word2);
    printf("\nWord3 is %s", word3);
    
    printf("\nWord1 length is %d, first letter is %c and last letter is %c", strlen(word1), word1[0], word1[strlen(word1)-1]);
    printf("\nWord2 length is %d, first letter is %c and last letter is %c", strlen(word2), word2[0], word2[strlen(word2)-1]);
    printf("\nWord3 length is %d, first letter is %c and last letter is %c", strlen(word3), word3[0], word3[strlen(word3)-1]);
    
    printf("\nWord1 first letter using pointer is %c and last letter %c", *word1, *(word1 /*or &word1[0]*/ + strlen(word1) - 1));

    char animal[] = "";
    strncpy(animal, "cat", MAX);
    printf("\nContents of animal = %s", animal);
    strncpy(animal, "horse", MAX);
    printf("\nContents of animal = %s", animal);
    printf(" --> String is missing NULL terminator \\0");
    strncpy(animal, "horse", 6);
    printf("\nContents of animal = %s", animal);
    
}