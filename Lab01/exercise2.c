#include <stdio.h>

int main()
{
	/*print all numbers from 1 to 16*/
	int start = 0;
	int x = 0;

	for (x = start; x <= (16*16) - 1; x++)
	{
		printf("%4x ", x);
		if (x % 16 == 0)
			printf("\n");
	};
	getchar();
	return 0;
}