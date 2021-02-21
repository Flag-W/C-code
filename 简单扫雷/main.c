#define _CRT_SECURE_NO_WARNINGS 1 

//扫雷小游戏
#include "game.h"

void game()
{
	char mine[ROWS][COLS] = {0};//11*11,存放布置好雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出雷的信息
	InitBoard(mine, ROWS, COLS, '0');//初始化
	InitBoard(show, ROWS, COLS, '*');//初始化
//	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
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
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while(input);
}



int main()
{
	test();
	return 0;
}

