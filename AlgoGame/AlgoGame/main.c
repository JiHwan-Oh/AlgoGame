#include <stdio.h>
#include <windows.h>
#include<time.h>
#include <conio.h>
#include "ui.h"

#define QUEUE_MAX 24

#define SPEED_NORMAL 1000
#define SPEED_DOUBLE 500
#define SPEED_TRIPLE 333

typedef struct Queue {
	int array[QUEUE_MAX];
	int front;
	int rear;
} Queue; 

Queue blockArray;
int simulationSpeed;

void showPC(PCInfo player)
{
	int x = GBOARD_ORIGIN_X + 4;
	int y = GBOARD_ORIGIN_Y + 2;
	SetCurrentCursorPos(x + (6 * player.x), y + (3 * player.y));
	switch (player.dir)
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

void deletePC(PCInfo player)
{
	int x = GBOARD_ORIGIN_X + 4;
	int y = GBOARD_ORIGIN_Y + 2;
	SetCurrentCursorPos(x + (6 * player.x), y + 3 * player.y);
	printf("  ");
}

void initBlockQueue()
{
	for (int i = 0; i < QUEUE_MAX; i++)
		blockArray.array[i] = -1;
	blockArray.front = 0;
	blockArray.rear = 0;
}

int isBlockArrayFull()
{
	if ((blockArray.rear + 1) > QUEUE_MAX) return 1;
	return 0;
}

void addBlock(int index)
{
	if (isBlockArrayFull())
		return;
	blockArray.array[blockArray.rear++] = index;
}

void deleteBlock(int index)
{
	if (blockArray.array[index] == -1)
		return;
	for (int i = index; i < blockArray.rear - 1; i++)
		blockArray.array[i] = blockArray.array[i + 1];
	blockArray.array[blockArray.rear - 1] = -1;
	blockArray.rear--;
}

void changeSpeed()
{
	switch (simulationSpeed) {
	case SPEED_NORMAL:
		simulationSpeed = SPEED_DOUBLE;
		break;
	case SPEED_DOUBLE:
		simulationSpeed = SPEED_TRIPLE;
		break;
	case SPEED_TRIPLE:
		simulationSpeed = SPEED_NORMAL;
		break;
	default:
		break;
	}
}

void emptyBlockArray()
{
	for (int i = 0; i < QUEUE_MAX; i++)
		blockArray.array[i] = -1;
}

void resetStage()
{
	/*
	PCInfo iPCInfo = initialPCPos[curStageInfo];
	player.x = iPCInfo.x;
	player.y = iPCInfo.y;
	player.dir = iPCInfo.dir;
	*/
	emptyBlockArray();
	removeMap();
	drawMap();
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void showBlockArray();

void clearBlockArray()
{
	int blockArrayX = BLOCK_ARRAY_ORIGIN_X + 2;
	int blockArrayY = BLOCK_ARRAY_ORIGIN_Y + 1;
	for (int i = 0; i < 24; i++)
	{
		if (blockArray.array[i] == -1)
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
				printf("  ");
			}
		blockArrayX += 12;
	}
}

void init()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("mode con cols=155 lines=52");
	RemoveCursor();
}

int main()
{
	init();

	// drawTitle();

	initBlockQueue();
	drawUI();
	// resetStage();

	addBlock(1);
	addBlock(2);
	addBlock(3);
	addBlock(4);
	// deleteBlock(2);
	showBlockArray();

	PCInfo player = initialPCPos[curStageInfo];

	/*
	player.dir = 1;
	player.x = 1; // 12x12에서 x좌표(0~11)
	player.y = 5; // 12x12에서 y좌표(0~11)
	*/

	for (int i = 0; i < 9; i++)
	{
		showPC(player);
		Sleep(simulationSpeed);
		if (i == 4)
		{
			player.dir = 0;
			showPC(player);
			Sleep(simulationSpeed);
		}
		deletePC(player);
		switch (player.dir)
		{
		case 0:
			player.y -= 1;
			break;
		case 1:
			player.x += 1;
			break;
		case 2:
			player.y += 1;
			break;
		case 3:
			player.x -= 1;
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
		if (blockArray.array[i] == -1)
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
				if (block[blockArray.array[i]][y][x] == 1)
					printf("■");
			}
		blockArrayX += 12;
	}
}