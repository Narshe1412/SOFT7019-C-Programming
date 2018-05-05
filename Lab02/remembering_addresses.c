#include <stdio.h>

int main()
{
    int bytesNeededForAddress = sizeof(void *);
    printf("The number of bytes needed for a memory address (pointer) is %d bytes.", bytesNeededForAddress);

    int num = 3;
    int num2 = 21;
    void * pAddressOfNum = &num;
    printf("\n\npAddressOfNum stores the number %p", pAddressOfNum);
    printf("\nNum2 stores the number %p", &num2);
    printf("\npAddressOfNum can hold an address of %d bytes", sizeof(pAddressOfNum));

    int *pAddressOfIntNum = NULL;
    pAddressOfIntNum = &num;
    printf("\n\nInt Value at address %p is %d", pAddressOfIntNum, *pAddressOfIntNum);

    int *pAddressOfIntNum2 = NULL;
    pAddressOfIntNum2 = &num2;
    printf("\nInt Value at address %p is %d", pAddressOfIntNum2, *pAddressOfIntNum2);

    char letterX = 'x';
    char *pAddressOfLetter = NULL;
    pAddressOfLetter = &letterX;
    printf("\nChar Value at address %p is %c", pAddressOfLetter, *pAddressOfLetter);

}