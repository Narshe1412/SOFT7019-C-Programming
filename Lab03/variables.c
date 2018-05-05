#include <stdio.h>
#include <stdlib.h>

int global_num=5;

int test()
{
    int test_local_num = 5;
    static int test_static_num = 0;
    test_local_num++;
    test_static_num++;

    if (test_static_num >= 3) 
    {
        printf("\nThat's enough!");
        return 0;
    }

    void *pStack;
    asm volatile ("mov %%esp,%0;" : "=g" (pStack));
    printf("\nTest: Value of ESP register is %p\n", pStack);
    
    printf("\nTest: global_num at %p with value %d", &global_num, global_num);
    global_num++;
    printf("\nTest: global_num after increment at %p and value %d", &global_num, global_num);

    printf("\nTest: test_local_num at %p and value %d", &test_local_num, test_local_num);
    printf("\nTest: test_static_num at %p and value %d", &test_static_num, test_static_num);
    
}

int main()
{
    int main_local_num=33;

    void *pStack;
    asm volatile ("mov %%esp,%0;" : "=g" (pStack));
    printf("\n\nMain: Value of ESP register is %p\n", pStack);

    printf("\nMain: global_num at %p with value %d", &global_num, global_num);
    printf("\nMain: main_local_num at %p", &main_local_num);
    
    test();
    test();
    test();
    test();
    test();

    printf("\nMain: global_num after increment at %p and value %d", &global_num, global_num);
    
    return 0;
}
