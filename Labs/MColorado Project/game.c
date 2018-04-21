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

	initialise_game(p_game_info, "John", "Annie");
	draw_banner();
	display_board_positions();
	print_status(p_game_info);


	while (p_game_info->finished == False) {
		process_move(p_game_info);
		display_board(p_game_info->board);
		check_winning_moves(p_game_info);
		print_status(p_game_info);
	}
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
	printf("\n --------------------------\n   WELCOME TO TIC TAC TOE   \n --------------------------");
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
	case P1_TURN:
		printf("\n%s's turn. ", p_game_info->playerNames[0]);
		break;
	case P2_TURN:
		printf("\n%s's turn. ", p_game_info->playerNames[1]);
		break;
	default:
		printf("\nError: cannot retrieve game status.");
		break;
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
		printf("Please enter a digit between 0 and 9: ");
		char c = myGetChar();
		int slot = c - '0';
		int row = -1;
		int col = -1;

		if (slot > 0 && slot <= 9) {
			get_row_col(slot, &row, &col);
			char boardstate = game_info->board[row][col];
			if (boardstate == SPACE) {
				if (game_info->status == P1_TURN) {
					game_info->board[row][col] = X_SYMBOL;
					game_info->status = P2_TURN;
				}
				else if (game_info->status == P2_TURN) {
					game_info->board[row][col] = O_SYMBOL;
					game_info->status = P1_TURN;
				}
				isValid = True;
				game_info->finished = is_board_full(game_info);
				if (game_info->finished && (game_info->status != P1_WON && game_info->status != P2_WON)) {
					game_info->status = DRAW;
				}
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

boolean is_board_full(struct game* game_info) {

	for (int r = 0; r < BOARD_SIZE; r++) {
		for (int c = 0; c < BOARD_SIZE; c++) {
			if (game_info->board[r][c] == SPACE) return False;
		}
	}
	return True;
}

void check_winning_moves(struct game* game_info) {

	int moves[8][6] = {
		{ 0,0,0,1,0,2 }, /* 1,2,3 */
		{ 1,0,1,1,1,2 }, /* 4,5,6 */
		{ 2,0,1,1,2,2 }, /* 7,8,9 */
		{ 0,0,1,0,2,0 }, /* 1,4,7 */
		{ 0,1,1,1,2,1 }, /* 2,5,8 */
		{ 0,2,1,2,2,2 }, /* 3,6,9 */
		{ 0,0,1,1,2,2 }, /* 1,5,9 */
		{ 0,2,1,1,2,0}   /* 3,5,7 */
	};
	int i = 0;

	while ((game_info->status == P1_TURN || game_info->status == P2_TURN) && i < 8) {
		if ((game_info->board[moves[i][0]][moves[i][1]] != SPACE) &&
			(game_info->board[moves[i][0]][moves[i][1]] == game_info->board[moves[i][2]][moves[i][3]]) &&
			(game_info->board[moves[i][0]][moves[i][1]] == game_info->board[moves[i][4]][moves[i][5]])) {
			if (game_info->status == P1_TURN) {
				game_info->status = P1_WON;
			}
			else if (game_info->status == P2_TURN) {
				game_info->status = P2_WON;
			}
			else {
				/* Board is in an invalid state */
				printf("Something wrong happened with the game. Please play again.");
			}
			game_info->finished = True;
		}
		i++;
	}
}