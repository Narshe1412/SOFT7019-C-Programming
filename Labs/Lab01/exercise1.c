#include <stdio.h>

int main() 
{
	int number = 31;
	char letter = 'A';

	printf("\n number is\t %d : %x\n", number, number);
	printf("\n letter is\t char %c : hex %x : ascii %d\n", letter, letter, letter);

	printf("Press enter to continue");
	getchar();
	return 0;
}