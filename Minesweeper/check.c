#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "check.h"

void checkMine(Board board, int playerRow, int playerCol, int* gameOver){
	
	if (board.tile[playerRow][playerCol].is_mine == 1){
		*gameOver = 1;
		return;
	}
	
	if (playerRow < board.rows){
		if (board.tile[playerRow + 1][playerCol].is_mine == 1){ // Up
			++board.tile[playerRow][playerCol].num_surrounding_mines;
		}
	}
	
	if (playerCol < board.cols){
		if (playerRow < board.rows){
			if (board.tile[playerRow + 1][playerCol + 1].is_mine == 1){ // Up - Right
				++board.tile[playerRow][playerCol].num_surrounding_mines;
			}
		}
		
		if (board.tile[playerRow][playerCol + 1].is_mine == 1){ // Right
			++board.tile[playerRow][playerCol].num_surrounding_mines;
		}
		
		if (playerRow > 0){
			if (board.tile[playerRow - 1][playerCol + 1].is_mine == 1){ // Down - Right
				++board.tile[playerRow][playerCol].num_surrounding_mines;
			}
		}
	}
	
	if (playerRow > 0){
		if (board.tile[playerRow - 1][playerCol].is_mine == 1){ // Down
			++board.tile[playerRow][playerCol].num_surrounding_mines;
		}
	}
	
	if (playerCol > 0){
		if (playerRow > 0){
			if (board.tile[playerRow - 1][playerCol - 1].is_mine == 1){ // Down - Left
				++board.tile[playerRow][playerCol].num_surrounding_mines;
			}
		}
		
		if (board.tile[playerRow][playerCol - 1].is_mine == 1){ // Left
			++board.tile[playerRow][playerCol].num_surrounding_mines;
		}
		
		if (playerRow < board.rows){
			if (board.tile[playerRow + 1][playerCol - 1].is_mine == 1){ // Up - Left
				++board.tile[playerRow][playerCol].num_surrounding_mines;
			}
		}
	}
	board.tile[playerRow][playerCol].appearance = (char)board.tile[playerRow][playerCol].num_surrounding_mines;
	
	if (board.tile[playerRow][playerCol].num_surrounding_mines == 0){
		
		board.tile[playerRow][playerCol].appearance = '0'; // Reveal blank space
		
		if (playerRow < board.rows){
			checkMine(board, playerRow + 1, playerCol, gameOver); // Up
		}
	}
	
	if (playerCol < board.cols){
		if (playerRow < board.rows){
			checkMine(board, playerRow + 1, playerCol + 1, gameOver); // Up - Right
		}
		
		checkMine(board, playerRow, playerCol + 1, gameOver); // Right
		
		if (playerRow > 0){
			checkMine(board, playerRow, playerCol, gameOver); // Down - Right
		}
	}
	
	if (playerRow > 0){
		checkMine(board, playerRow - 1, playerCol, gameOver); // Down
	}
	
	if (playerCol > 0){
		if (playerRow > 0){
			checkMine(board, playerRow - 1, playerCol - 1, gameOver); // Down - Left
		}
		
		checkMine(board, playerRow, playerCol - 1, gameOver); // Left
		
		if (playerRow < board.rows){
			checkMine(board, playerRow + 1, playerCol - 1, gameOver); // Up - Left
		}
	}
	
}
