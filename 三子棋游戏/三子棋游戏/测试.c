#define  _CRT_SECURE_NO_WARNINGS 1

#include "��������Ϸ.h"
void menu()
{
	printf("***********************\n");
	printf("***1.paly     0.exit***\n");
	printf("***********************\n");
}

void game()
{
	char ret = 0;//׼���ý�����Ӯ���ַ���
	//����--����������̵���Ϣ
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)//����
	{
		PlayMove(board, ROW, COL);//�����
		system("cls");
		DisplayBoard(board, ROW, COL);
		
		ret = IsWin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'R')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//������
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
		printf("���Ӯ\n");
	}
	else if (ret == 'x')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");  
	}
}
	

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("��ʼ��Ϸ��������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}