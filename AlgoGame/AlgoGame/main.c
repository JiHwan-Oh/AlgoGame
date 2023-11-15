#include <stdio.h>
#include <windows.h>
#include <time.h>
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
int simulationSpeed = 1000;

PCInfo player;

int key = 0;
int shield = 0;
void resetStage();

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
	default:
		break;
	}
	Sleep(simulationSpeed);
	if (map[curStageInfo][player.x][player.y] == 2) // 현재 위치가 함정일 경우
	{
		if (shield == 0)
		{
			resetStage();
		}
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

// 오브젝트 블록 기능 수행 함수
void goStraight()
{
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

void turnLeft()
{
	deletePC(player);
	player.dir = (player.dir + 3) % 4;
}

void turnRight()
{
	deletePC(player);
	player.dir = (player.dir + 5) % 4;
}

void gatherItem()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (map[curStageInfo][player.x][player.y] == 5)
	{
		drawObject(x + (6 * player.x), y + (3 * player.y), 1);
		key += 1;
	}
	else if (map[curStageInfo][player.x][player.y] == 6)
	{
		drawObject(x + (6 * player.x), y + (3 * player.y), 1);
		shield += 1;
	}
}

void useKey()
{
	if (key == 0)
		return;
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (map[curStageInfo][player.x - 1][player.y] == 4) // 좌측 칸이 좌물쇠인 경우
	{
		drawObject(x + (6 * (player.x - 1)), y + (3 * player.y), 1);
	}
	else if (map[curStageInfo][player.x + 1][player.y] == 4) // 우측 칸이 좌물쇠인 경우
	{
		drawObject(x + (6 * (player.x + 1)), y + (3 * player.y), 1);
	}
	else if (map[curStageInfo][player.x][player.y+1] == 4) // 위 칸이 좌물쇠인 경우
	{
		drawObject(x + (6 * player.x), y + (3 * (player.y + 1)), 1);
	}
	else if (map[curStageInfo][player.x][player.y-1] == 4) // 아래 칸이 좌물쇠인 경우
	{
		drawObject(x + (6 * player.x), y + (3 * (player.y - 1)), 1);
	}
	key--;
}

void useShield()
{
	if (shield == 0)
		return;
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (map[curStageInfo][player.x - 1][player.y] == 2) // 좌측 칸이 장애물인 경우
	{
		drawObject(x + (6 * (player.x - 1)), y + (3 * player.y), 1);
	}
	else if (map[curStageInfo][player.x + 1][player.y] == 2) // 우측 칸이 장애물인 경우
	{
		drawObject(x + (6 * (player.x + 1)), y + (3 * player.y), 1);
	}
	else if (map[curStageInfo][player.x][player.y + 1] == 2) // 위 칸이 장애물인 경우
	{
		drawObject(x + (6 * player.x), y + (3 * (player.y + 1)), 1);
	}
	else if (map[curStageInfo][player.x][player.y - 1] == 2) // 아래 칸이 장애물인 경우
	{
		drawObject(x + (6 * player.x), y + (3 * (player.y - 1)), 1);
	}
	shield--;
}

void usePortal()
{
	if (map[curStageInfo][player.x][player.y] == 3) // 현재 위치가 포탈인 경우
	{
		for(int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
			{
				if (map[curStageInfo][j][i] == 3 && player.x != i && player.y != j)
				{
					player.x = i;
					player.y = j;
					return;
				}
			}
	}
}
//

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

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
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
	player = initialPCPos[curStageInfo];

	for(int i = 0; i < 4; i++)
		addBlock(0);
	addBlock(1);
	for (int i = 0; i < 4; i++)
		addBlock(0);
	showBlockArray();
	for (int i = 0; ; i++)
	{
		showPC(player);
		if (blockArray.array[i] == -1)
			break;
		switch (blockArray.array[i])
		{
		case 0:
			goStraight();
			break;
		case 1:
			turnLeft();
			break;
		case 2:
			turnRight();
			break;
		case 3:
			gatherItem();
			break;
		case 4:
			useKey();
			break;
		case 5:
			useShield();
			break;
		case 6:
			usePortal();
			break;
		default:
			break;
		}
	}

	SetCurrentCursorPos(0, 42);
	printf("\n\n\n\n\n");
	return 0;
}
