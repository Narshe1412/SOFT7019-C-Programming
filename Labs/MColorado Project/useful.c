#include <math.h>
#include <time.h>

enum Bool {False, True};
typedef enum Bool boolean;

/* Gets a valid character from console input */
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

/*Get random number < max using a random seed with time()*/
int getRandomNum(int max)
{
	srand((unsigned int)time(NULL));
	return rand() % max;
}