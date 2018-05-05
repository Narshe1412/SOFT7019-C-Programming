#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/* Captures command line arguments */
int main(int argc, char* argv[])
{
	/* If there's 2 arguments .exe + 2, executes the game, otherwise throws error. */
	if (argc == 3) {
		play_game(argv[1], argv[2]);
	}
	else {
		printf("\nThis program requires the following arguments: main.exe player1 player2\n You passed %d", argc - 1);
	}
	getch();
	return 0;
}
