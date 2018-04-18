#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

const char SPACE = '-';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';


void play_game()
{
	printf("Xs and Os!\n");
	
	struct game* p_game_info = (struct game*) malloc(sizeof(struct game));

	printf("This is the pointer %p", p_game_info);

}
