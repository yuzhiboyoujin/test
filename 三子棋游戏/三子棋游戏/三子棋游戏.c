#define  _CRT_SECURE_NO_WARNINGS 1
#include "三子棋游戏.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)//若以后要改成10*10的棋盘，行数可以改，但列数改不了。
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);//打印一行的数据。
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");//打印分隔符。
//		}
//	}
//}

//优化：行和列都可以改
void DisplayBoard(char board[ROW][COL], int row, int col)//若以后要改成10*10的棋盘，行数可以改，但列数改不了。
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	while (1)
	{
		printf("请输入要下的坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'o';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标输入超出范围，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	printf("电脑走：\n");
	while (1)
	{
		a = rand() % row;
		b = rand() % col;
		if (board[a][b] == ' ')
		{
			board[a][b] = 'x';
			break;
		}
	}
}

//返回1表示棋盘满了
//返回0表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//判断横三行是否连起来
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//判断竖三列是否连起来
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//for (i = 0; i < col; i++)//判断左斜边是否连起来
	//{
	//	if (board[0][i] == board[1][i+1] && board[1][i+1] == board[2][i+2] && board[0][i] != ' ')
	//	{
	//		return board[0][i];
	//	}
	//}
	//for (i = 0; i < row; i++)//判断右斜边是否连起来
	//{
	//	if (board[i][2] == board[i+1][1] && board[i+1][1] == board[i+2][0] && board[i][1] != ' ')
	//	{
	//		return board[i][2];
	//	}
	//}
	
	////两个对角线判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	////判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'E';
	}
	return 'R';
}