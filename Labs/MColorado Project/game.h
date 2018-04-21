#ifndef _GAME_H_
#define _GAME_H_

#define MAX_NAME_LEN 50
#define BOARD_SIZE 3
enum Bool { False, True };
enum status { P1_TURN, P2_TURN, P1_WON, P2_WON, DRAW };
typedef enum Bool boolean;
extern const char SPACE;
extern const char X_SYMBOL;
extern const char O_SYMBOL;

struct game {
	char board[BOARD_SIZE][BOARD_SIZE];
	char playerNames[2][MAX_NAME_LEN];
	int status;
	boolean finished;
};

void play_game();
void initialise_game(struct game* p_game_info, char* name1, char* name2);
void draw_banner();
void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_status(struct game* p_game_info);
void display_board_positions();
void get_row_col(int position, int *row, int *col);
void process_move(struct game* game_info);
boolean is_board_full(struct game* game_info);
void check_winning_moves(struct game* game_info);
#endif