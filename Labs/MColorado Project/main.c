#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(int argc, char* argv[])
{
	if (argc == 3) {
		play_game(argv[1], argv[2]);
	}
	else {
		printf("\nThis program requires the following arguments: main.exe player1 player2\n You passed %d", argc - 1);
	}
	getch();
	return 0;
}
