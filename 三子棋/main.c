#define _CRT_SECURE_NO_WARNINGS 1 
//三子棋游戏
#include<stdio.h>
#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("******1.play  0.exit ********\n");
	printf("*****************************\n");
}
//游戏实现
void game()
{
	//数组存放棋盘信息
	char board[ROW][COL] = { 0 };//希望一开始时全是空格
	char ret = 0;
	InitBoard(board, ROW, COL);//初始化棋盘
	//   |   |   
	//---|---|---
	//   |   |      理想一开始的棋盘
	//---|---|---
	//   |   | 

	DisplayBoard(board, ROW, COL);//显示棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家走
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);//判断游戏状态
		if (ret != 'C')
			break;

		ComputerMove(board, ROW, COL);//电脑走
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//判断游戏状态
			break;
	}

	if (ret == 'Q')
	{
		printf("平局\n");
	}
	if (ret == '#')
	{
		printf("电脑赢\n");
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}

}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出\n");
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