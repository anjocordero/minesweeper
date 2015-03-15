#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"
#include "check.h"

int verify_play(Board board, int playerRow, int playerCol){
	
	if (playerRow < 0 || playerRow > (board.rows -1)){ //checks if within bounds

		return 0;
	}
	
	if (playerCol < 0 || playerCol > (board.cols -1)){ //checks if within bounds
		
		return 0;
	}
	
	if (board.tile[playerRow][playerCol].appearance == '#' || board.tile[playerRow][playerCol].appearance == '!' || board.tile[playerRow][playerCol].appearance == '?'){
		return 1; 
	} 
	
	else if (board.tile[playerRow][playerCol].appearance != '!' || board.tile[playerRow][playerCol].appearance != '?'){
		printf("This tile is already revealed.\n");
		return 0;	
	}
	
	else{
		return 1;
	}
	
}
	
	
void get_play(Board board, int* mines_left, int gameOver){
	int playerRow;
	int playerCol;
	int playerAction;
	int validPlay;
	
	printf("Enter row a row between 0-%d and a column between 0-%d: ", board.rows - 1, board.cols - 1);
	scanf("%d %d", &playerRow, &playerCol);
	
	validPlay = verify_play(board, playerRow, playerCol); 
	
	while(!validPlay){
		printf("Enter row a row between 0-%d and a column between 0-%d: ", board.rows - 1, board.cols - 1);
		scanf("%d %d", &playerRow, &playerCol);
	}
	
	if (validPlay){
		if(board.tile[playerRow][playerCol].appearance =='!'){
			printf("Enter Action\n0. UnMark\n1. Cancel\n");
			printf("Action: ");
			scanf("%d", &playerAction);
				if (playerAction == 0){
					board.tile[playerRow][playerCol].appearance = '#';
					board.tile[playerRow][playerCol].visibility = CONCEALED;
					*mines_left = *mines_left + 1;
				}
				
				if (playerAction == 1){
					get_play(board, mines_left); //FIX ME
				}
		}
		
		
		else if (board.tile[playerRow][playerCol].appearance == '?'){
			printf("Enter Action\n0. UnQuestion\n1. Cancel\n");
			printf("Action: ");
			scanf("%d", &playerAction);
				if (playerAction == 0){
					board.tile[playerRow][playerCol].appearance = '#';
					board.tile[playerRow][playerCol].visibility = CONCEALED;
				}
				
				if (playerAction == 1){
					get_play(board, mines_left); //FIX ME
				}
		}
			
		
		else{
			printf("Enter Action\n0. Reveal\n1. Question\n2. Mark\n3. Cancel\n");
			printf("Action: ");
			scanf("%d", &playerAction);
		
			if (playerAction == 3){
				get_play(board, mines_left); //FIX ME
			}
		
			if (playerAction == 2){
				board.tile[playerRow][playerCol].appearance = '!';
				board.tile[playerRow][playerCol].visibility = MARKED;
				*mines_left = *mines_left - 1;
			}
			
			if (playerAction == 1){
				board.tile[playerRow][playerCol].appearance = '?';
				board.tile[playerRow][playerCol].visibility = QUESTIONED;
			}
			
			if (playerAction == 0){
				if (board.tile[playerRow][playerCol].is_mine == 1){
					gameOver = 1;
				}
				
				// if checkMine(board, playerRow, playerCol)
			}
		}
	}

}

void play_game(Board board){
	int gameOver = 0;
	//int gameWin = 0;
	
	int num_mines_left = board.num_mines;
	
    while(!gameOver){
		printf("There are %d mines left.\n", num_mines_left);
		print_board(board);
		get_play(board, &num_mines_left, &gameOver);
		//check_game_over(gameBoard, &gameOver, &gameWin);
		
	}
    

}
