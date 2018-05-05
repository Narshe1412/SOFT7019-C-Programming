#include <stdio.h>
#include <limits.h>

int main()
{
    void *stack_ptr;
    asm volatile ("mov %%ebp,%0;" : "=g" (stack_ptr));
    printf("Value of EBP register is %#p\n", stack_ptr);

    int num = 0xFFFF;
    char letter1 = 'A';
    char letter2 = 'B';
    int num2;

    printf("\nletter1 has a value of %d : %x : %c", letter1, letter1, letter1);
    printf("\nletter2 has a value of %d : %x : %c", letter2, letter2, letter2);
    printf("\nletter1 is allocated %d : %d", sizeof(letter1), CHAR_BIT * sizeof(letter1));

    printf("\nletter1 max value is %d", CHAR_MAX);
    printf("\nletter1 min value is %d", CHAR_MIN);
    
    printf("\nnum has a value fo %d : %#x", num, num);
    printf("\nnum uses %d bytes : %d bits", sizeof(num), CHAR_BIT * sizeof(num));
    printf("\nMax min values in num are %d / %d", INT_MAX, INT_MIN);

    printf("\n\nStart location of num is %#p", &num);
    printf("\nStart location of letter1 is %#p", &letter1);
    printf("\nStart location of letter2 is %#p", &letter2);
    printf("\nStart location of num2 is %#p", &num2);
    
    printf("\nPress return to continue...");
    //getchar();
    return 0;
}
