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