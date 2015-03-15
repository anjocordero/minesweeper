#ifndef BOARD_H
#define BOARD_H

enum Visibility {REVEALED, CONCEALED, MARKED, QUESTIONED};

typedef struct TILE_STRUCT{
	int is_mine;
	int num_surrounding_mines;
	enum Visibility visibility;
	char appearance; 
}Tile;

typedef struct BOARD_STRUCT{
	int rows;
	int cols;
	int num_mines;
	Tile** tile;
}Board;


Board create_board(int rows, int cols, int num_mines, int seed);
void print_board(Board board);
void destroy_board(Board board);


#endif
