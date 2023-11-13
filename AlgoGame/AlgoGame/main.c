#include <stdio.h>
#include <windows.h>
#include<time.h>
#include <conio.h>
#include "ui.h"

int curPosX;
int curPosY;
int blockQueue[24] = { 0, 0, 1, 5, 1, 3, 6, 1, 0, 3, 4, 3, 1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void init()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	system("mode con cols=155 lines=52");
	RemoveCursor();
}

int main()
{
	init();

	// drawTitle();

	drawUI();

	// 블록배열 그리는 테스트
	int bax = BLOCK_ARRAY_ORIGIN_X + 2;
	int bay = BLOCK_ARRAY_ORIGIN_Y + 1;
	for (int i = 0; i < 24; i++)
	{
		if (blockQueue[i] == -1)
			break;
		if (i % 6 == 0 && i != 0)
		{
			bax = BLOCK_ARRAY_ORIGIN_X + 2;
			bay += 6;
		}
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
			{
				SetCurrentCursorPos(bax + (x * 2), bay + y);
				if (block[blockQueue[i]][y][x] == 1)
					printf("■");
			}
		bax += 12;
	}
	/*
	SetCurrentCursorPos(curPosX, curPosY);
	curPosX = 4;
	curPosY = 2;
	for (int y = 0; y < 36; y++)
		for (int x = 0; x < 36; x++)
		{
			SetCurrentCursorPos(curPosX + (x * 2), curPosY + y);
			printf("■");
		}
	*/
	SetCurrentCursorPos(0, 42);
	printf("\n\n\n\n\n");
}