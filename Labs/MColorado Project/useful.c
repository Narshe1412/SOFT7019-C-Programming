#include <math.h>
#include <time.h>

enum Bool {False, True};
typedef enum Bool boolean;

char myGetChar()
{
	char res = getchar();

	boolean finish = False;
	char dummy = res;

	while (finish == False) {
		if (dummy == '\n')
			finish = True;
		else
			dummy = getchar();
	}

	return res;
}

/*Get random position for the cursor using a random seed using time()*/
int getRandomNum(int max)
{
	srand((unsigned int)time(NULL));
	return rand() % max;
}