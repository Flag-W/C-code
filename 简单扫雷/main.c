#define _CRT_SECURE_NO_WARNINGS 1 

//ɨ��С��Ϸ
#include "game.h"

void game()
{
	char mine[ROWS][COLS] = {0};//11*11,��Ų��ú��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų���׵���Ϣ
	InitBoard(mine, ROWS, COLS, '0');//��ʼ��
	InitBoard(show, ROWS, COLS, '*');//��ʼ��
//	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);

}

void menu()
{
	printf("****************************\n");
	printf("***********1.play***********\n");
	printf("***********0.exit***********\n");
	printf("****************************\n");
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while(input);
}



int main()
{
	test();
	return 0;
}

