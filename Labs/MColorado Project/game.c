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
	draw_banner();
	display_board(p_game_info->board);

	//test3
	p_game_info->board[0][0] = X_SYMBOL; // top left X
	p_game_info->board[2][2] = O_SYMBOL; // bottom right o
	display_board(p_game_info->board);
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

	printf("\nGame initialised");
}

void draw_banner()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // 15 white lines
	printf("\n ---------------\n   GAME STATUS   \n ---------------");
}

void display_board(char board[3][3])
{
	printf("\n\n    %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n   ---+---+---");
	printf("\n    %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n   ---+---+---");
	printf("\n    %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

