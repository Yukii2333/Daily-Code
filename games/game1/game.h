#pragma once

//���Խ�ͷ�ļ��а���������ͷ�ļ��ڰ������Խ�ͷ�ļ���Դ�ļ��оͲ����ٰ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 3//��
#define ROW 3//��  ����ȫ�ֱ������ں����޸�


//����
void init_board(char board[ROW][COL], int row, int col);//��ʼ��

void print_board(char board[ROW][COL], int row, int col);//��ӡ

void player_turn(char board[ROW][COL], int row, int col);//��һغ�

void pc_turn(char board[ROW][COL], int row, int col);//���Իغ�

char is_win(char board[ROW][COL], int row, int col);//�ж���Ӯ
