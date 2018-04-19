#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "useful.h"

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
	print_status(p_game_info);
	display_board_positions();

	/*
	//test3
	p_game_info->board[0][0] = X_SYMBOL; // top left X
	p_game_info->board[2][2] = O_SYMBOL; // bottom right o
	display_board(p_game_info->board);

	int row = -1;
	int col = -1;
	get_row_col(2, &row, &col);
	printf("\nPosition 2 should be (0,1) and is <%d,%d>", row, col);
	get_row_col(5, &row, &col);
	printf("\nPosition 5 should be (1,1) and is <%d,%d>", row, col);
	get_row_col(9, &row, &col);
	printf("\nPosition 9 should be (2,2) and is <%d,%d>", row, col);
	get_row_col(10, &row, &col);
	printf("\nPosition 10 is not valid so (-1,-1) and is <%d,%d>", row, col);
	*/
	process_move(p_game_info);
	display_board(p_game_info->board);
	
	
	// Test step 5
	process_move(p_game_info);
	display_board(p_game_info->board);
	p_game_info->status = P2_TURN;
	process_move(p_game_info);
	display_board(p_game_info->board);
	process_move(p_game_info);
	display_board(p_game_info->board);


}

void initialise_game(struct game* p_game_info, char* name1, char* name2)
{
	p_game_info->status = P1_TURN;

	for (int r = 0; r < BOARD_SIZE; r++) {
		for (int c = 0; c < BOARD_SIZE; c++) {
			p_game_info->board[r][c] = SPACE;
		}
	}

	p_game_info->finished = False;
	strncpy(p_game_info->playerNames[0], name1, MAX_NAME_LEN);
	strncpy(p_game_info->playerNames[1], name2, MAX_NAME_LEN);

}

void draw_banner()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // 15 white lines
	printf("\n ---------------\n   GAME STATUS   \n ---------------");
}

void display_board(char board[BOARD_SIZE][BOARD_SIZE])
{
	printf("\n\n    %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n   ---+---+---");
	printf("\n    %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n   ---+---+---");
	printf("\n    %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void print_status(struct game* p_game_info)
{
	if (p_game_info->finished) {
		//game over
		switch (p_game_info->status)
		{
		case P1_WON:
			printf("\nWell done %s, you are the winner!", p_game_info->playerNames[0]);
			break;
		case P2_WON:
			printf("\nWell done %s, you are the winner!", p_game_info->playerNames[1]);
			break;
		case DRAW:
			printf("\nGame over. It's a draw!");
			break;
		default:
			printf("\nError: cannot retrieve game status.");
			break;
		}
	}
	else {
		//game still going
		switch (p_game_info->status)
		{
		case P1_TURN:
			printf("\n%s's turn.", p_game_info->playerNames[0]);
			break;
		case P2_TURN:
			printf("\n%s's turn.", p_game_info->playerNames[1]);
			break;
		default:
			printf("\nError: cannot retrieve game status.");
			break;
		}
	}
}

void display_board_positions()
{
	printf("\n\n    1 | 2 | 3 ");
	printf("\n   ---+---+---");
	printf("\n    4 | 5 | 6 ");
	printf("\n   ---+---+---");
	printf("\n    7 | 8 | 9 \n");
}

void get_row_col(int position, int *row, int *col) {
	if (position < 1 || position > 9) {
		/* Return invalid coordinates on invalid position parameter */
		*row = -1;
		*col = -1;
	}
	else {
		*row = (position - 1) / 3;
		*col = (position - 1) % 3;
	}
}

void process_move(struct game* game_info)
{
	boolean isValid = False;
	
	while (!isValid)
	{
		printf("\nPlease enter a digit between 0 and 9: ");
		char c = myGetChar();
		int slot = c - '0';
		int row = -1;
		int col = -1;
		
		if (slot > 0 && slot <= 9) {
			get_row_col(slot, &row, &col);
			char boardstate = game_info->board[row][col];
			if (boardstate == SPACE) {
				if (game_info->status == P1_TURN) { game_info->board[row][col] = X_SYMBOL; }
				if (game_info->status == P2_TURN) { game_info->board[row][col] = O_SYMBOL; }
				isValid = True;
			}
			else {
				printf("\nThis position is already taken. Choose another. ");
			}
		}
		else {
			printf("\nPlease enter a valid number. ");
		}
	}
}