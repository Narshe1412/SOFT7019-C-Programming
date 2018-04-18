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

	initialise_game(p_game_info, "John", "Annie");

}

void initialise_game(struct game* p_game_info, char* name1, char* name2)
{
	p_game_info->status = P1_TURN;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			p_game_info->board[r][c] = SPACE;
		}
	}

	p_game_info->finished = False;
	strncpy(p_game_info->playerNames[0], name1, MAX_NAME_LEN);
	strncpy(p_game_info->playerNames[1], name2, MAX_NAME_LEN);

	printf("Game initialised");
}

