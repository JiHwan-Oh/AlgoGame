#include <stdio.h>
#include <windows.h>
#include<time.h>
#include <conio.h>
#include "ui.h"

int blockQueue[24] = { 0, 0, 1, 5, 1, 3, 6, 1, 0, 3, 4, 3, 1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

typedef struct pc
{
	int pcPosX;
	int pcPosY;
	int direction;
}PC;

void showPC(PC player)
{
	int x = GBOARD_ORIGIN_X + 4;
	int y = GBOARD_ORIGIN_Y + 2;
	SetCurrentCursorPos(x + (6 * player.pcPosX), y + (3 * player.pcPosY));
	switch (player.direction)
	{
	case 0:
		printf("↑");
		break;
	case 1:
		printf("→");
		break;
	case 2:
		printf("↓");
		break;
	case 3:
		printf("←");
	default :
		break;
	}
}

void deletePC(PC player)
{
	int x = GBOARD_ORIGIN_X + 4;
	int y = GBOARD_ORIGIN_Y + 2;
	SetCurrentCursorPos(x + (6 * player.pcPosX), y + 3 * player.pcPosY);
	printf("  ");
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

void showBlockArray();

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("mode con cols=155 lines=52");
	RemoveCursor();

	drawUI();
	showBlockArray();

	PC player;

	player.direction = 1;
	player.pcPosX = 1; // 12x12에서 x좌표(0~11)
	player.pcPosY = 5; // 12x12에서 y좌표(0~11)
	for (int i = 0; i < 9; i++)
	{
		showPC(player);
		Sleep(1000);
		if (i == 4)
		{
			player.direction = 0;
			showPC(player);
			Sleep(1000);
		}
		deletePC(player);
		switch (player.direction)
		{
		case 0:
			player.pcPosY -= 1;
			break;
		case 1:
			player.pcPosX += 1;
			break;
		case 2:
			player.pcPosY += 1;
			break;
		case 3:
			player.pcPosX -= 1;
			break;
		default:
			break;
		}
	}



	SetCurrentCursorPos(0, 42);
	printf("\n\n\n\n\n");
	return 0;
}

void showBlockArray()
{
	int blockArrayX = BLOCK_ARRAY_ORIGIN_X + 2;
	int blockArrayY = BLOCK_ARRAY_ORIGIN_Y + 1;
	for (int i = 0; i < 24; i++)
	{
		if (blockQueue[i] == -1)
			break;
		if (i % 6 == 0 && i != 0)
		{
			blockArrayX = BLOCK_ARRAY_ORIGIN_X + 2;
			blockArrayY += 6;
		}
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
			{
				SetCurrentCursorPos(blockArrayX + (x * 2), blockArrayY + y);
				if (block[blockQueue[i]][y][x] == 1)
					printf("■");
			}
		blockArrayX += 12;
	}
}