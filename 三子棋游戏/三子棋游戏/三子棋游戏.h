#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void InitBoard(char board[ROW][COL], int row, int col);//函数申明
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//告诉我们游戏的四种状态
//玩家赢   o
//电脑赢   x
//平局     E
//继续     R
char IsWin(char board[ROW][COL], int row, int col);
