#pragma once

//在自建头文件中包含了其他头文件在包含了自建头文件的源文件中就不用再包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 3//列
#define ROW 3//行  定义全局变量便于后续修改


//声明
void init_board(char board[ROW][COL], int row, int col);//初始化

void print_board(char board[ROW][COL], int row, int col);//打印

void player_turn(char board[ROW][COL], int row, int col);//玩家回合

void pc_turn(char board[ROW][COL], int row, int col);//电脑回合

char is_win(char board[ROW][COL], int row, int col);//判断输赢
