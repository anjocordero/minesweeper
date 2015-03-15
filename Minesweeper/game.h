#ifndef GAME_H
#define GAME_H

void play_game(Board board);
int verify_play(Board board, int playerRow, int playerCol);
void get_play(Board board, int* mines_left, int* gameOver);




#endif
