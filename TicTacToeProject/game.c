#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "useful.h"

const char SPACE = '-';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

/* Main Program Loop */
void play_game(char *player1, char *player2)
{
	printf("Xs and Os!\nA C project by Manuel Colorado\n");

	/* Creates the Struct with the game state */
	struct game* p_game_info = (struct game*) malloc(sizeof(struct game));

	/* Calls the starting up methods to initialise state and draw the board */
	initialise_game(p_game_info, player1, player2);
	draw_banner();
	display_board_positions();
	print_status(p_game_info);

	/* While the game is not finished ...*/
	while (p_game_info->finished == False) {
		process_move(p_game_info);				/* Get a new move */
		display_board(p_game_info->board);		/* Display the resulting board */
		print_status(p_game_info);				/* Display the resulting state */
	}

	/* When the game ends, free allocated memory */
	free (p_game_info);
}


/* Initialises the game state */
void initialise_game(struct game* p_game_info, char* name1, char* name2)
{
	/* Assigns the P1 turn as initial turn */
	p_game_info->status = P1_TURN;

	/* Initialises all board slots to SPACES */
	for (int r = 0; r < BOARD_SIZE; r++) {
		for (int c = 0; c < BOARD_SIZE; c++) {
			p_game_info->board[r][c] = SPACE;
		}
	}

	/* Assigns the finished status to false (not finished) */
	p_game_info->finished = False;

	/* Randomizes the players */
	if (getRandomNum(2)) {
		strncpy(p_game_info->playerNames[0], name1, MAX_NAME_LEN);
		strncpy(p_game_info->playerNames[1], name2, MAX_NAME_LEN);
	}
	else {
		strncpy(p_game_info->playerNames[0], name2, MAX_NAME_LEN);
		strncpy(p_game_info->playerNames[1], name1, MAX_NAME_LEN);
	}
}

/* Creates the starting banner */
void draw_banner()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); // 15 white lines
	printf("\n --------------------------\n   WELCOME TO TIC TAC TOE   \n --------------------------");
}

/* Displays board positions as instructions to players */
void display_board_positions()
{
	printf("\n\n    1 | 2 | 3 ");
	printf("\n   ---+---+---");
	printf("\n    4 | 5 | 6 ");
	printf("\n   ---+---+---");
	printf("\n    7 | 8 | 9 \n");
}


/* Displays the current state of the board to the screen */
void display_board(char board[BOARD_SIZE][BOARD_SIZE])
{
	printf("\n\n    %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n   ---+---+---");
	printf("\n    %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n   ---+---+---");
	printf("\n    %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

/* Displays a message based on the current status of the game*/
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
		printf("\nError: cannot retrieve game status."); /* Fallback if the game is in a corrupted state */
		break;
	}
}

/* Gets the current board coordinates based on the assigned position */
void get_row_col(int position, int *row, int *col) {
	if (position < 1 || position > 9) {
		/* Return invalid coordinates on invalid position parameter */
		*row = -1;
		*col = -1;
	}
	else {
		/* The following algorithm is for 0-8 positions, so we deduct 1 from the "pretty" position the players introduces */
		*row = (position - 1) / 3; 
		*col = (position - 1) % 3;
	}
}

/* Processes an input from keyboard */
void process_move(struct game* game_info)
{
	boolean isValid = False;

	/* Keep asking while the input is not valid */
	while (!isValid)
	{
		printf("Please enter a digit between 0 and 9: ");
		char c = myGetChar();
		int slot = c - '0';
		int row = -1;
		int col = -1;

		/* Do the algorithm only if the input is a number from 1 to 9 */
		if (slot > 0 && slot <= 9) {
			/* Get the coordinates */
			get_row_col(slot, &row, &col);
			/* Get the symbol at those coordinates */
			char boardstate = game_info->board[row][col];
			/* If the symbol is a SPACE, it can be used */
			if (boardstate == SPACE) {
				/* Check whose current player, assign its symbol, flips turn over to the next player */
				if (game_info->status == P1_TURN) {
					game_info->board[row][col] = X_SYMBOL;
					game_info->status = P2_TURN;
				}
				else if (game_info->status == P2_TURN) {
					game_info->board[row][col] = O_SYMBOL;
					game_info->status = P1_TURN;
				}
				/* Input is now valid */
				isValid = True;
				/* Check if the board is full */
				game_info->finished = is_board_full(game_info);
				/* Check if the board is on a winning state */
				check_winning_moves(game_info);
				/* If the board is full and no one won, stop the game and mark a draw*/
				if (game_info->finished && (game_info->status != P1_WON && game_info->status != P2_WON)) {
					game_info->status = DRAW;
				}
			}
			else { /* Show error if the position is already taken */
				printf("\nThis position is already taken. ");
			}
		}
		else { /* Show error if the input is not a valid number */
			printf("\nPlease enter a valid number. ");
		}
	}
}

/* Checks if the board is completely used = no SPACE slots are available */
boolean is_board_full(struct game* game_info) {

	/* Loop all the board slots. If it finds a SPACE automatically stop the loop and return False = the board is not full */
	for (int r = 0; r < BOARD_SIZE; r++) {
		for (int c = 0; c < BOARD_SIZE; c++) {
			if (game_info->board[r][c] == SPACE) return False;
		}
	}
	return True; /* The board is full */
}

/* Check if the board is in a state that is considered winning */
void check_winning_moves(struct game* game_info) {

	/* This array contains all the coordinates the game will consider as winning, if the elements at those coordinates are the same */
	int moves[8][6] = {	 /*Positions*/
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

	/* We loop as long as
		- Status is either P1_TURN o P2_TURN. Other states mean the game has ended
		- There's still elements in the array (i= 0 to 8) */
	while ((game_info->status == P1_TURN || game_info->status == P2_TURN) && i < 8) {
		
		if ((game_info->board[moves[i][0]][moves[i][1]] != SPACE) && /* if the first element is not a SPACE and */
			(game_info->board[moves[i][0]][moves[i][1]] == game_info->board[moves[i][2]][moves[i][3]]) && /* this first element equals the second element */
			(game_info->board[moves[i][0]][moves[i][1]] == game_info->board[moves[i][4]][moves[i][5]])) { /* and equals the third element then */
				/* then we can say that all three elements are equal, and they are not SPACES so */

			/* If it's player 1 turn's, he won */
			if (game_info->status == P1_TURN) {
				game_info->status = P1_WON;
			}
			/* If it's player 2 turn's, he won*/
			else if (game_info->status == P2_TURN) {
				game_info->status = P2_WON;
			}
			else {
				/* Otherwise the board is in an invalid state */
				printf("Something wrong happened with the game. Please play again.");
			}
			/* We mark the game as finished */
			game_info->finished = True;
		}
		i++;
	}
}