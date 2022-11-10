#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY 10

int arounded_mine(char mine[ROWS][COLS], int x, int y);

void init_board(char board[ROWS][COLS], int rows, int cols, char set);

void print_board(char board[ROWS][COLS], int row, int col);

void set_mine(char mine[ROWS][COLS], int row, int col);

void sweep_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);