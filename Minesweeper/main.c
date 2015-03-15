#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"

void check_argc(int argc){
	
	if (argc < 5){
		 printf("Not enough arguments entered\n");
		 printf("Usage minesweeper.out num_rows num_columns num_mines seed_num\n");
		 exit(0);
	}
	
	if (argc > 5){
		 printf("Too many arguments entered\n");
		 printf("Usage minesweeper.out num_rows num_columns num_mines seed_num\n");
		 exit(0);
	}
	
}

int main(int argc, char** argv){
	check_argc(argc);
	
	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);
	int num_mines = atoi(argv[3]);
	int seed = atoi(argv[4]);
	
	Board gameBoard =  create_board(rows, cols, num_mines, seed);
	play_game(gameBoard);
	destroy_board(gameBoard);
	
	
	return 0;
}
