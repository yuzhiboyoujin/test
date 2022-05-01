#define  _CRT_SECURE_NO_WARNINGS 1
#include "��������Ϸ.h"

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

//void DisplayBoard(char board[ROW][COL], int row, int col)//���Ժ�Ҫ�ĳ�10*10�����̣��������Ըģ��������Ĳ��ˡ�
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);//��ӡһ�е����ݡ�
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");//��ӡ�ָ�����
//		}
//	}
//}

//�Ż����к��ж����Ը�
void DisplayBoard(char board[ROW][COL], int row, int col)//���Ժ�Ҫ�ĳ�10*10�����̣��������Ըģ��������Ĳ��ˡ�
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
	printf("�����\n");
	while (1)
	{
		printf("������Ҫ�µ�����:");
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
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("�������볬����Χ������������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	printf("�����ߣ�\n");
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

//����1��ʾ��������
//����0��ʾ����û��
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
				return 0;//û��
			}
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//�жϺ������Ƿ�������
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//�ж��������Ƿ�������
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//for (i = 0; i < col; i++)//�ж���б���Ƿ�������
	//{
	//	if (board[0][i] == board[1][i+1] && board[1][i+1] == board[2][i+2] && board[0][i] != ' ')
	//	{
	//		return board[0][i];
	//	}
	//}
	//for (i = 0; i < row; i++)//�ж���б���Ƿ�������
	//{
	//	if (board[i][2] == board[i+1][1] && board[i+1][1] == board[i+2][0] && board[i][1] != ' ')
	//	{
	//		return board[i][2];
	//	}
	//}
	
	////�����Խ����ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	////�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'E';
	}
	return 'R';
}