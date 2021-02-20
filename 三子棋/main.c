#define _CRT_SECURE_NO_WARNINGS 1 
//��������Ϸ
#include<stdio.h>
#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("******1.play  0.exit ********\n");
	printf("*****************************\n");
}
//��Ϸʵ��
void game()
{
	//������������Ϣ
	char board[ROW][COL] = { 0 };//ϣ��һ��ʼʱȫ�ǿո�
	char ret = 0;
	InitBoard(board, ROW, COL);//��ʼ������
	//   |   |   
	//---|---|---
	//   |   |      ����һ��ʼ������
	//---|---|---
	//   |   | 

	DisplayBoard(board, ROW, COL);//��ʾ����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�����
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);//�ж���Ϸ״̬
		if (ret != 'C')
			break;

		ComputerMove(board, ROW, COL);//������
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//�ж���Ϸ״̬
			break;
	}

	if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}

}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳�\n");
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