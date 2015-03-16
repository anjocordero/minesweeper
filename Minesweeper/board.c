#include <stdio.h>
#include <stdlib.h>
#include "board.h"

Board create_board(int rows, int cols, int num_mines, int seed){
	int i,j;
	int xCoord;
	int yCoord;
	int tempXCoord;
	int tempYCoord;
	Board board;
	
	board.rows = rows;
	board.cols = cols;
	board.num_mines = num_mines;
	
	board.tile = (Tile**)malloc(rows * sizeof(Tile*));
	
	for (i = 0; i < rows; i++){
		board.tile[i] = (Tile*)malloc(cols * sizeof(Tile));
	}
	
	srand(seed);
	
	for (i = 0; i < num_mines; i++){
		xCoord = rand() % (board.rows);
		yCoord = rand() % (board.cols);
		
		if(board.tile[xCoord][yCoord].is_mine == 1){
			tempXCoord = rand() % (board.rows);
			tempYCoord = rand() % (board.cols);
			
			printf("Placing mine at %d, %d\n", tempXCoord, tempYCoord);
			board.tile[tempXCoord][tempYCoord].is_mine = 1;
		}
		
		else{
			printf("Placing mine at %d, %d\n", xCoord, yCoord);
			board.tile[xCoord][yCoord].is_mine = 1;
		}
	}
	
	for (i = 0; i < board.rows; i++){
		for(j = 0; j < board.cols; j++){
			board.tile[i][j].appearance = '#';
			board.tile[i][j].visibility = CONCEALED;
		}
	}
	
	return board;
}

void print_board(Board board){
	int i, j;
	
	for (i = (board.rows - 1); i >= 0; i--){
        for (j = 0; j < board.cols; j++){
            if ( j == (board.cols - 1)){ 
                printf("%c\n", board.tile[i][j].appearance);
           }
           
			else{
				if (j == 0){
						printf("%d ", (i));
				}
					
				printf("%c ", board.tile[i][j].appearance);
			}
		}
	}

	
	printf("  ");
	for (j = 0; j < board.cols; j++){
		printf("%d ", j);
		if ( j == (board.cols - 1)){
				printf("\n");
		}
	}

}
	
void destroy_board(Board board){
	int i;
	
	for (i = 0; i < board.rows; i++){
		free(board.tile[i]);
	}
	
	free(board.tile);
}
