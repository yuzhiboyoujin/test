#define  _CRT_SECURE_NO_WARNINGS 1

#include "三子棋游戏.h"
void menu()
{
	printf("***********************\n");
	printf("***1.paly     0.exit***\n");
	printf("***********************\n");
}

void game()
{
	char ret = 0;//准备好接收输赢的字符。
	//数组--用来存放棋盘的信息
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)//下棋
	{
		PlayMove(board, ROW, COL);//玩家下
		system("cls");
		DisplayBoard(board, ROW, COL);
		
		ret = IsWin(board, ROW, COL);//判断输赢
		if (ret != 'R')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑走
		system("cls");
		DisplayBoard(board, ROW, COL);
		
		ret = IsWin(board, ROW, COL);
		if (ret != 'R')
		{
			break;
		}
		ret = IsWin(board, ROW, COL);
	}
	if (ret == 'o')
	{
		printf("玩家赢\n");
	}
	else if (ret == 'x')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");  
	}
}
	

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("开始游戏：三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}