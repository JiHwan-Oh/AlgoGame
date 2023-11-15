#include "block.h"
#include "object.h"
#include "map.h"

// 스크린
#define SCREEN_WIDTH 75
#define SCREEN_HEIGHT 46

#define SCREEN_ORIGIN_X 0
#define SCREEN_ORIGIN_Y 0
// 맵
#define GBOARD_WIDTH 36
#define GBOARD_HEIGHT 37

#define GBOARD_ORIGIN_X 2
#define GBOARD_ORIGIN_Y 1
// 블록
#define BLOCK_WIDTH 47
#define BLOCK_HEIGHT 6

#define BLOCK_ORIGIN_X 2
#define BLOCK_ORIGIN_Y 39
// 블록배열
#define BLOCK_ARRAY_WIDTH 35
#define BLOCK_ARRAY_HEIGHT 24

#define BLOCK_ARRAY_ORIGIN_X 78
#define BLOCK_ARRAY_ORIGIN_Y 14
// 스테이지 정보
#define INFO_WIDTH 25
#define INFO_HEIGHT 12

#define INFO_ORIGIN_X 78
#define INFO_ORIGIN_Y 1
// PLAY/STOP
#define PS_WIDTH 3
#define PS_HEIGHT 6

#define PS_ORIGIN_X 132
#define PS_ORIGIN_Y 7
// RESET
#define RESET_WIDTH 3
#define RESET_HEIGHT 5

#define RESET_ORIGIN_X 132
#define RESET_ORIGIN_Y 1
// BACK
#define BACK_WIDTH 3
#define BACK_HEIGHT 5

#define BACK_ORIGIN_X 142
#define BACK_ORIGIN_Y 1
// 배속
#define SPEED_WIDTH 3
#define SPEED_HEIGHT 6

#define SPEED_ORIGIN_X 142
#define SPEED_ORIGIN_Y 7
// 대화창
#define DIALOGUE_WIDTH 24
#define DIALOGUE_HEIGHT 6

#define DIALOGUE_ORIGIN_X 100
#define DIALOGUE_ORIGIN_Y 39


void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

COORD GetCurrentCursorPos(void)
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;
	return curPoint;
}

void drawScreen()
{
	int x, y;
	for (y = 0; y <= SCREEN_HEIGHT; y++)
	{
		SetCurrentCursorPos(SCREEN_ORIGIN_X, SCREEN_ORIGIN_Y + y);
		if (y == SCREEN_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= SCREEN_HEIGHT; y++)
	{
		SetCurrentCursorPos(SCREEN_ORIGIN_X + (SCREEN_WIDTH + 1) * 2, SCREEN_ORIGIN_Y + y);
		if (y == SCREEN_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < SCREEN_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(SCREEN_ORIGIN_X + x * 2, SCREEN_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < SCREEN_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(SCREEN_ORIGIN_X + x * 2, SCREEN_ORIGIN_Y + SCREEN_HEIGHT);
		printf("━");
	}
}

void drawGameBoard()
{
	int x, y;
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
		if (y == GBOARD_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= GBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
		if (y == GBOARD_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < GBOARD_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < GBOARD_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
		printf("━");
	}
}

void drawBlock()
{
	int x, y;
	for (y = 0; y <= BLOCK_HEIGHT; y++)
	{
		SetCurrentCursorPos(BLOCK_ORIGIN_X, BLOCK_ORIGIN_Y + y);
		if (y == BLOCK_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= BLOCK_HEIGHT; y++)
	{
		SetCurrentCursorPos(BLOCK_ORIGIN_X + (BLOCK_WIDTH + 1) * 2, BLOCK_ORIGIN_Y + y);
		if (y == BLOCK_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < BLOCK_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(BLOCK_ORIGIN_X + x * 2, BLOCK_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < BLOCK_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(BLOCK_ORIGIN_X + x * 2, BLOCK_ORIGIN_Y + BLOCK_HEIGHT);
		printf("━");
	}
	for (int x = 0; x < 7; x++)
		for (int y = 0; y < 5; y++)
		{
			SetCurrentCursorPos(14 + (x * 12), 40 + y);
			printf("┃");
		}

	int blockPosX = 4;
	int blockPosY = 40;
	for (int i = 0; i < 7; i++)
	{
		SetCurrentCursorPos(blockPosX, blockPosY);
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
			{
				SetCurrentCursorPos(blockPosX + (x * 2), blockPosY + y);
				if (block[i][y][x] == 1)
					printf("■");
			}
		blockPosX += 12;
	}
}

void drawBlockArray()
{
	int x, y;
	for (y = 0; y <= BLOCK_ARRAY_HEIGHT; y++)
	{
		SetCurrentCursorPos(BLOCK_ARRAY_ORIGIN_X, BLOCK_ARRAY_ORIGIN_Y + y);
		if (y == BLOCK_ARRAY_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= BLOCK_ARRAY_HEIGHT; y++)
	{
		SetCurrentCursorPos(BLOCK_ARRAY_ORIGIN_X + (BLOCK_ARRAY_WIDTH + 1) * 2, BLOCK_ARRAY_ORIGIN_Y + y);
		if (y == BLOCK_ARRAY_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < BLOCK_ARRAY_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(BLOCK_ARRAY_ORIGIN_X + x * 2, BLOCK_ARRAY_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < BLOCK_ARRAY_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(BLOCK_ARRAY_ORIGIN_X + x * 2, BLOCK_ARRAY_ORIGIN_Y + BLOCK_ARRAY_HEIGHT);
		printf("━");
	}
	for (int x = 0; x < 7; x++)
		for (int y = 0; y < 5; y++)
		{
			SetCurrentCursorPos(14 + (x * 12), 40 + y);
			printf("┃");
		}
	// 세로선
	int bax;
	int bay;
	bax = BLOCK_ARRAY_ORIGIN_X + 12;
	bay = BLOCK_ARRAY_ORIGIN_Y + 1;
	for (int i = 0; i < 4; i++)
	{
		for (int x = 0; x < 5; x++)
			for (int y = 0; y < 5; y++)
			{
				SetCurrentCursorPos(bax + (x * 12), bay + y + (6 * i));
				printf("┃");
			}
	}
	// 가로선
	bax = BLOCK_ARRAY_ORIGIN_X + 2;
	bay = BLOCK_ARRAY_ORIGIN_Y + 6;
	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 6; y++)
			for (int x = 0; x < 9; x++)
			{
				SetCurrentCursorPos(bax + x + (12 * y), bay + (6 * i));
				printf("━");
			}
	}
}

void showStageInfo()
{
	int x, y;
	for (y = 0; y <= INFO_HEIGHT; y++)
	{
		SetCurrentCursorPos(INFO_ORIGIN_X, INFO_ORIGIN_Y + y);
		if (y == INFO_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= INFO_HEIGHT; y++)
	{
		SetCurrentCursorPos(INFO_ORIGIN_X + (INFO_WIDTH + 1) * 2, INFO_ORIGIN_Y + y);
		if (y == INFO_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < INFO_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(INFO_ORIGIN_X + x * 2, INFO_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < INFO_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(INFO_ORIGIN_X + x * 2, INFO_ORIGIN_Y + INFO_HEIGHT);
		printf("━");
	}
	int infoX = INFO_ORIGIN_X + 2;
	int infoY = INFO_ORIGIN_Y + 1;
	SetCurrentCursorPos(infoX, infoY);
	printf("[CHAPTER] : %d, [STAGE] : %d", curStageInfo / 10 + 1, curStageInfo % 10 + 1);
	SetCurrentCursorPos(infoX, infoY + 3);
	printf("ITEM");
	SetCurrentCursorPos(infoX, infoY + 4);
	printf("★ : 0           ♥: 0");
	SetCurrentCursorPos(infoX, infoY + 7);
	printf("COMMAND BLOCK COUNT : 9");
}

void drawPlayStopButton()
{
	int x, y;
	for (y = 0; y <= PS_HEIGHT; y++)
	{
		SetCurrentCursorPos(PS_ORIGIN_X, PS_ORIGIN_Y + y);
		if (y == PS_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= PS_HEIGHT; y++)
	{
		SetCurrentCursorPos(PS_ORIGIN_X + (PS_WIDTH + 1) * 2, PS_ORIGIN_Y + y);
		if (y == PS_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < PS_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(PS_ORIGIN_X + x * 2, PS_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < PS_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(PS_ORIGIN_X + x * 2, PS_ORIGIN_Y + PS_HEIGHT);
		printf("━");
	}
	int psX = PS_ORIGIN_X + 2;
	int psY = PS_ORIGIN_Y + 2;
	SetCurrentCursorPos(psX, psY);
	printf("PLAY");
}

void drawResetButton()
{
	int x, y;
	for (y = 0; y <= RESET_HEIGHT; y++)
	{
		SetCurrentCursorPos(RESET_ORIGIN_X, RESET_ORIGIN_Y + y);
		if (y == RESET_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= RESET_HEIGHT; y++)
	{
		SetCurrentCursorPos(RESET_ORIGIN_X + (RESET_WIDTH + 1) * 2, RESET_ORIGIN_Y + y);
		if (y == RESET_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < RESET_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(RESET_ORIGIN_X + x * 2, RESET_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < RESET_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(RESET_ORIGIN_X + x * 2, RESET_ORIGIN_Y + RESET_HEIGHT);
		printf("━");
	}
	int resetX = RESET_ORIGIN_X + 2;
	int resetY = RESET_ORIGIN_Y + 2;
	SetCurrentCursorPos(resetX, resetY);
	printf("RESET");
}

void drawExitButton()
{
	int x, y;
	for (y = 0; y <= BACK_HEIGHT; y++)
	{
		SetCurrentCursorPos(BACK_ORIGIN_X, BACK_ORIGIN_Y + y);
		if (y == BACK_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= BACK_HEIGHT; y++)
	{
		SetCurrentCursorPos(BACK_ORIGIN_X + (BACK_WIDTH + 1) * 2, BACK_ORIGIN_Y + y);
		if (y == BACK_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < BACK_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(BACK_ORIGIN_X + x * 2, BACK_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < BACK_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(BACK_ORIGIN_X + x * 2, BACK_ORIGIN_Y + BACK_HEIGHT);
		printf("━");
	}
	int backX = BACK_ORIGIN_X + 2;
	int backY = BACK_ORIGIN_Y + 2;
	SetCurrentCursorPos(backX, backY);
	printf("EXIT");
}

void showSpeedButton()
{
	int x, y;
	for (y = 0; y <= SPEED_HEIGHT; y++)
	{
		SetCurrentCursorPos(SPEED_ORIGIN_X, SPEED_ORIGIN_Y + y);
		if (y == SPEED_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= SPEED_HEIGHT; y++)
	{
		SetCurrentCursorPos(SPEED_ORIGIN_X + (SPEED_WIDTH + 1) * 2, SPEED_ORIGIN_Y + y);
		if (y == SPEED_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < SPEED_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(SPEED_ORIGIN_X + x * 2, SPEED_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < SPEED_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(SPEED_ORIGIN_X + x * 2, SPEED_ORIGIN_Y + SPEED_HEIGHT);
		printf("━");
	}

	int speed = 1;
	int speedX = SPEED_ORIGIN_X + 2;
	int speedY = SPEED_ORIGIN_Y + 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("▶▶▶");
	speedX += 2;
	speedY += 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("%d", speed);
}

void drawDialogue()
{
	int x, y;
	for (y = 0; y <= DIALOGUE_HEIGHT; y++)
	{
		SetCurrentCursorPos(DIALOGUE_ORIGIN_X, DIALOGUE_ORIGIN_Y + y);
		if (y == DIALOGUE_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= DIALOGUE_HEIGHT; y++)
	{
		SetCurrentCursorPos(DIALOGUE_ORIGIN_X + (DIALOGUE_WIDTH + 1) * 2, DIALOGUE_ORIGIN_Y + y);
		if (y == DIALOGUE_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < DIALOGUE_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(DIALOGUE_ORIGIN_X + x * 2, DIALOGUE_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < DIALOGUE_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(DIALOGUE_ORIGIN_X + x * 2, DIALOGUE_ORIGIN_Y + DIALOGUE_HEIGHT);
		printf("━");
	}
	for (int x = 0; x < 7; x++)
		for (int y = 0; y < 5; y++)
		{
			SetCurrentCursorPos(14 + (x * 12), 40 + y);
			printf("┃");
		}

	// 대화 출력
	int diaX = DIALOGUE_ORIGIN_X + 2;
	int diaY = DIALOGUE_ORIGIN_Y + 1;
	SetCurrentCursorPos(diaX, diaY++);
	printf("Hello");
	SetCurrentCursorPos(diaX, diaY++);
	printf("My name is ");
	SetCurrentCursorPos(diaX, diaY++);
	printf("My age is ");
	SetCurrentCursorPos(diaX, diaY++);
	printf("Im from ");
	SetCurrentCursorPos(diaX, diaY++);
	printf("My major is ");
}

void drawObject(int x, int y, int idx)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			SetCurrentCursorPos(x + (2 * i), y + j);
			int obj = objectArray[idx][i][j];
			switch (obj)
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("▲");
				break;
			case 3:
				printf("●");
				break;
			case 4:
				printf("★");
				break;
			case 5:
				printf("☆");
				break;
			case 6:
				printf("♡");
				break;
			default:
				break;
			}
		}
	}
}

void removeMap()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			drawObject(x + (6 * j), y + (3 * i), 0);
		}
}

void drawMap()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			int index = map[curStageInfo][i][j];
			if(index == 7) // 도착점 빨간색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			drawObject(x + (6 * j), y + (3 * i), index);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
}

void drawUI()
{
	drawScreen();
	drawGameBoard();
	drawBlock();
	drawBlockArray();
	showStageInfo();
	drawPlayStopButton();
	drawResetButton();
	drawDialogue();
	drawExitButton();
	showSpeedButton();
	drawMap();
}