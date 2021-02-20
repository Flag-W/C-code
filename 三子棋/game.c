#define _CRT_SECURE_NO_WARNINGS 1 
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);//��ӡ����
			else
				printf(" %c ", board[i][j]);
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if ((i < row - 1)&&(j<col-1))
				printf("---|");//��ӡ�ָ���
			if ((i<row-1)&&(j==col-1))
				printf("---");
		}
		printf("\n");
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i, j;
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>\n");
		scanf("%d%d", &i, &j);
		if (1 <= j && j <= col && 1 <= i && i <= row)//�ж�����ĺϷ��� 
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("�����ѱ�ռ��\n");
		}
		else
			printf("���겻�Ϸ�������������\n");
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != ' ')
			return board[i][0];
	for (j = 0; j < col; j++)
		if (board[0][j] == board[1][j] && board[2][j] == board[1][j] && board[0][j] != ' ')
			return board[0][j];
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]&&board[1][1]!=' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0]&&board[1][1]!=' '))
		return board[1][1];
	for (i = 0, j = 0; i < row; i++)
	{
		for(j = 0; j < col;j++ )
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	if (i == row)
		return 'Q';
}

