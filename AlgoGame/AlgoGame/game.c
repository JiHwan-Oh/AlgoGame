﻿#include "game.h"


void removeAll()
{
	for (int i = 2; i < 148; i++)
		for (int j = 2; j < 46; j++)
		{
			SetCurrentCursorPos(i, j);
			printf(" ");
		}
}

void drawTitle()
{
	BasicSetting();
	while (1)
	{
		drawScreen();
		int m = CheckMouse();
		if (m == 1)
		{
			if (mouse_x >= START_ORIGIN_X && mouse_x <= START_ORIGIN_X + 2 * START_WIDTH && mouse_y >= START_ORIGIN_Y && mouse_y <= START_ORIGIN_Y + START_HEIGHT) // start 버튼 클릭시
			{
				removeAll();
				return;
			}
			else if (mouse_x >= MANUAL_ORIGIN_X && mouse_x <= MANUAL_ORIGIN_X + 2 * MANUAL_WIDTH && mouse_y >= MANUAL_ORIGIN_Y && mouse_y <= MANUAL_ORIGIN_Y + MANUAL_HEIGHT) // manual 버튼 클릭시
			{
				removeAll();
				drawManual();
			}
		}
		int x, y;
		for (y = 0; y <= START_HEIGHT; y++)
		{
			SetCurrentCursorPos(START_ORIGIN_X, START_ORIGIN_Y + y);
			if (y == START_HEIGHT)
				printf("┗");
			else if (y == 0)
				printf("┏");
			else
				printf("┃");
		}
		for (y = 0; y <= START_HEIGHT; y++)
		{
			SetCurrentCursorPos(START_ORIGIN_X + (START_WIDTH + 1) * 2, START_ORIGIN_Y + y);
			if (y == START_HEIGHT)
				printf("┛");
			else if (y == 0)
				printf("┓");
			else
				printf("┃");
		}
		for (x = 1; x < START_WIDTH + 1; x++)
		{
			SetCurrentCursorPos(START_ORIGIN_X + x * 2, START_ORIGIN_Y);
			printf("━");
		}
		for (x = 1; x < START_WIDTH + 1; x++)
		{
			SetCurrentCursorPos(START_ORIGIN_X + x * 2, START_ORIGIN_Y + START_HEIGHT);
			printf("━");
		}
		int startX = START_ORIGIN_X + 8;
		int startY = START_ORIGIN_Y + 2;
		SetCurrentCursorPos(startX, startY);
		printf("시작하기");
		for (y = 0; y <= MANUAL_HEIGHT; y++)
		{
			SetCurrentCursorPos(MANUAL_ORIGIN_X, MANUAL_ORIGIN_Y + y);
			if (y == MANUAL_HEIGHT)
				printf("┗");
			else if (y == 0)
				printf("┏");
			else
				printf("┃");
		}
		for (y = 0; y <= MANUAL_HEIGHT; y++)
		{
			SetCurrentCursorPos(MANUAL_ORIGIN_X + (MANUAL_WIDTH + 1) * 2, MANUAL_ORIGIN_Y + y);
			if (y == MANUAL_HEIGHT)
				printf("┛");
			else if (y == 0)
				printf("┓");
			else
				printf("┃");
		}
		for (x = 1; x < MANUAL_WIDTH + 1; x++)
		{
			SetCurrentCursorPos(MANUAL_ORIGIN_X + x * 2, MANUAL_ORIGIN_Y);
			printf("━");
		}
		for (x = 1; x < MANUAL_WIDTH + 1; x++)
		{
			SetCurrentCursorPos(MANUAL_ORIGIN_X + x * 2, MANUAL_ORIGIN_Y + MANUAL_HEIGHT);
			printf("━");
		}
		int manualX = MANUAL_ORIGIN_X + 8;
		int manualY = MANUAL_ORIGIN_Y + 2;
		SetCurrentCursorPos(manualX, manualY);
		printf("게임설명");
	}
}

void drawManual()
{
	while (1)
	{
		drawScreen();
		int m = CheckMouse();
		if (m == 1)
		{
			if (mouse_x >= MANUAL_BACK_ORIGIN_X && mouse_x <= MANUAL_BACK_ORIGIN_X + 2 * MANUAL_BACK_WIDTH && mouse_y >= MANUAL_BACK_ORIGIN_Y && mouse_y <= MANUAL_BACK_ORIGIN_Y + MANUAL_BACK_HEIGHT) // start 버튼 클릭시
			{
				removeAll();
				return;
			}
		}
		int x, y;
		for (y = 0; y <= MANUAL_BACK_HEIGHT; y++)
		{
			SetCurrentCursorPos(MANUAL_BACK_ORIGIN_X, MANUAL_BACK_ORIGIN_Y + y);
			if (y == MANUAL_BACK_HEIGHT)
				printf("┗");
			else if (y == 0)
				printf("┏");
			else
				printf("┃");
		}
		for (y = 0; y <= MANUAL_BACK_HEIGHT; y++)
		{
			SetCurrentCursorPos(MANUAL_BACK_ORIGIN_X + (MANUAL_BACK_WIDTH + 1) * 2, MANUAL_BACK_ORIGIN_Y + y);
			if (y == MANUAL_BACK_HEIGHT)
				printf("┛");
			else if (y == 0)
				printf("┓");
			else
				printf("┃");
		}
		for (x = 1; x < MANUAL_BACK_WIDTH + 1; x++)
		{
			SetCurrentCursorPos(MANUAL_BACK_ORIGIN_X + x * 2, MANUAL_BACK_ORIGIN_Y);
			printf("━");
		}
		for (x = 1; x < MANUAL_BACK_WIDTH + 1; x++)
		{
			SetCurrentCursorPos(MANUAL_BACK_ORIGIN_X + x * 2, MANUAL_BACK_ORIGIN_Y + MANUAL_BACK_HEIGHT);
			printf("━");
		}
		int backX = MANUAL_BACK_ORIGIN_X + 8;
		int backY = MANUAL_BACK_ORIGIN_Y + 2;
		SetCurrentCursorPos(backX, backY);
		printf("뒤로가기");
	}
}

// UI 모듈

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

void drawItemInfo() {
	int infoX = INFO_ORIGIN_X + 2;
	int infoY = INFO_ORIGIN_Y + 1;
	SetCurrentCursorPos(infoX, infoY + 4);
	printf("★ : %d           ♥ : %d", key, shield);
}

void drawBlockCountInfo() {
	int infoX = INFO_ORIGIN_X + 2;
	int infoY = INFO_ORIGIN_Y + 1;
	SetCurrentCursorPos(infoX, infoY + 7);
	printf("                          ");
	SetCurrentCursorPos(infoX, infoY + 7);
	printf("[COMMAND BLOCK COUNT] : %d", blockCount);
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
	printf("[ITEM]");
	drawItemInfo();
	drawBlockCountInfo();
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
	int speedX = SPEED_ORIGIN_X + 2;
	int speedY = SPEED_ORIGIN_Y + 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("▶    ");
	speedX += 2;
	speedY += 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("1");
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

// 오브젝트를 화면에 그림
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

// 화면 상의 맵을 지움
void removeMap()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			drawObject(x + (6 * j), y + (3 * i), 0);
}

// 화면에 맵을 그림
void drawMap()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
		{
			int index = map[curStageInfo][i][j];
			if (index == 7) // 도착점 빨간색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			drawObject(x + (6 * j), y + (3 * i), index);
		}
}

void showBlockArray()
{
	int blockArrayX = BLOCK_ARRAY_ORIGIN_X + 2;
	int blockArrayY = BLOCK_ARRAY_ORIGIN_Y + 1;
	for (int i = 0; i < 24 && blockArray.array[i] != -1; i++)
	{
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

void removeAllBlockArray()
{
	int blockArrayX = BLOCK_ARRAY_ORIGIN_X + 2;
	int blockArrayY = BLOCK_ARRAY_ORIGIN_Y + 1;
	for (int i = 0; i < 24; i++)
	{
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

void showPC()
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
	// 분리 필요
	Sleep(simulationSpeed);
	
	//
}

void deletePC()
{
	int x = GBOARD_ORIGIN_X + 4;
	int y = GBOARD_ORIGIN_Y + 2;
	SetCurrentCursorPos(x + (6 * player.x), y + 3 * player.y);
	printf("  ");
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

// Stage 모듈

void initBlockArray()
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

void addBlock(int objectIndex)
{
	if (isBlockArrayFull())
		return;
	blockArray.array[blockArray.rear++] = objectIndex;
	int infoX = INFO_ORIGIN_X + 2;
	int infoY = INFO_ORIGIN_Y + 1;
	blockCount++;
	drawBlockCountInfo();
}

void deleteBlock(int arrayIndex)
{
	if (blockArray.array[arrayIndex] == -1)
		return;
	for (int i = arrayIndex; i < blockArray.rear - 1; i++)
		blockArray.array[i] = blockArray.array[i + 1];
	blockArray.array[blockArray.rear - 1] = -1;
	blockArray.rear--;
	int infoX = INFO_ORIGIN_X + 2;
	int infoY = INFO_ORIGIN_Y + 1;
	blockCount--;
	drawBlockCountInfo();
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
	int speedX = SPEED_ORIGIN_X + 2;
	int speedY = SPEED_ORIGIN_Y + 2;
	speed += 1;
	if (speed == 4)
	{
		SetCurrentCursorPos(speedX, speedY);
		speed = 1;
		printf("      ");
	}
	SetCurrentCursorPos(speedX, speedY);
	if (speed == 1)
		printf("▶    ");
	else if (speed == 2)
		printf("▶▶  ");
	else if (speed == 3)
		printf("▶▶▶");
	speedX += 2;
	speedY += 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("%d", speed);
}

void resetBlockArray()
{
	initBlockArray();
	removeAllBlockArray();
	showBlockArray();
}

void resetPlayer() {
	player = initialPCPos[curStageInfo];
	showPC();
}

void resetItem() {
	key = 0;
	shield = 0;
	drawItemInfo();
}

void resetBlockCount() {
	blockCount = 0;
	drawBlockCountInfo();
}

void resetStage()
{
	removeMap();
	drawMap();
	resetPlayer();
	resetItem();
	resetBlockCount();
	resetBlockArray();
}

// 오브젝트 블록 기능 수행 함수
void goStraight()
{
	deletePC();
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
	deletePC();
	player.dir = (player.dir + 3) % 4;
}

void turnRight()
{
	deletePC();
	player.dir = (player.dir + 5) % 4;
}

void gatherItem()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (map[curStageInfo][player.x][player.y] == 5)
	{
		drawObject(x + (6 * player.x), y + (3 * player.y), 1);
		key++;
	}
	else if (map[curStageInfo][player.x][player.y] == 6)
	{
		drawObject(x + (6 * player.x), y + (3 * player.y), 1);
		shield++;
	}
}

void useKey()
{
	if (key == 0)
		return;
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (map[curStageInfo][player.x - 1][player.y] == 4) // 좌측 칸이 자물쇠인 경우
	{
		drawObject(x + (6 * (player.x - 1)), y + (3 * player.y), 1);
	}
	else if (map[curStageInfo][player.x + 1][player.y] == 4) // 우측 칸이 자물쇠인 경우
	{
		drawObject(x + (6 * (player.x + 1)), y + (3 * player.y), 1);
	}
	else if (map[curStageInfo][player.x][player.y + 1] == 4) // 위 칸이 자물쇠인 경우
	{
		drawObject(x + (6 * player.x), y + (3 * (player.y + 1)), 1);
	}
	else if (map[curStageInfo][player.x][player.y - 1] == 4) // 아래 칸이 자물쇠인 경우
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
		for (int i = 0; i < 12; i++)
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

// 블록 기능 수행
void executeBlock(int index) {
	switch (blockArray.array[index])
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

int checkStageClear() {
	if (map[curStageInfo][player.y][player.x] == 7) {
		// StageClear 화면 출력
		curStageInfo++;
		showStageInfo();
		resetStage();
		return 1;
	}
	return 0;
}

int checkTrap() {
	if (map[curStageInfo][player.y][player.x] == 2) // 현재 위치가 함정일 경우
	{
		if (shield == 0)
		{
			resetStage();
			return 1;
		}
	}
	return 0;
}

void checkEvent() {
	if (checkStageClear()) return;
	// if (checkWall()) return;
	if (checkTrap()) return;
}

//스크롤바 삭제하는 방법
void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//핸들 설정
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(handle, &info);//콘솔 스크린 버퍼값 가져오기

	COORD new_size =
	{
		//콘솔의 cols, lines 크기보다 스크린버퍼의 크기를 1 줄여주면 스크롤 바가 사라진다.
		info.srWindow.Right - info.srWindow.Left + 1,//콘솔창 사이즈 가로()
		info.srWindow.Bottom - info.srWindow.Top + 1 //콘솔창 사이즈 세로
	};

	SetConsoleScreenBufferSize(handle, new_size);// 적용
}

void BasicSetting() {
	HANDLE CIN, COUT;
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	remove_scrollbar(); //스크롤바 삭제(위에서 만든 함수 사용)
	//SetWindowLong(GetConsoleWindow(), GWL_STYLE, WS_CAPTION); //창스타일변경

	//입력 커서 숨기기
	CONSOLE_CURSOR_INFO curInfo = { 1 };
	//curInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	//curInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)-기본
	SetConsoleCursorInfo(COUT, &curInfo);

	//마우스 편집 막기(마우스로 드래그하면 글 복사할때처럼 박스 생기는거 막기)
	DWORD prevMode;
	GetConsoleMode(CIN, &prevMode);
	SetConsoleMode(CIN, prevMode & ~ENABLE_QUICK_EDIT_MODE);

	SetConsoleMode(COUT, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);// ?★ 마우스 입력모드로 변경
}

// 마우스 클릭 확인 및 좌표 반환
int CheckMouse()
{
	HANDLE CIN, COUT;
	CIN = GetStdHandle(STD_INPUT_HANDLE);// 핸들 설정
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);// 핸들 설정
	DWORD mode;

	GetConsoleMode(CIN, &mode); // 마우스 재활성화 ?★여기서 DWORD 값을 받는다
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);// 마우스 재활성화(만약 system() 함수를 사용할 시 마우스 재활성화를 해주어야 한다.)

	FlushConsoleInputBuffer(CIN);//콘솔 입력 버퍼를 플러시합니다. 현재 입력 버퍼에 있는 모든 입력 레코드는 삭제됩니다.
	ReadConsoleInput(CIN, &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임. 
	FlushConsoleInputBuffer(CIN);
	if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
	{
		//어떤 메뉴를 눌렀는지 알게하기 위해서(해당 메뉴의 좌표랑 비교)
		mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // 마우스의 X값 받아옴 
		mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // 마우스의 Y값 받아옴 

		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED && !(rec.Event.MouseEvent.dwEventFlags & MOUSE_MOVED)) { // 좌측 버튼이 클릭되었을 경우(드래그 시 연속 입력 X)
			return 1;
		}
	}
	return 0;//그 외 활동일경우(키보드, 마우스 드래그 등등)
}

// 임시 게임 시작 함수
void startGame() {
	BasicSetting();
	initBlockArray();
	drawUI();
	player = initialPCPos[curStageInfo];
	showBlockArray();
	showPC();
	while (1)
	{
		int m = CheckMouse();
		if (m == 1)
		{
			if (mouse_x >= BLOCK_ORIGIN_X && mouse_x <= BLOCK_ORIGIN_X + 2 * 42 && mouse_y >= BLOCK_ORIGIN_Y && mouse_y <= BLOCK_ORIGIN_Y + BLOCK_HEIGHT) // 블록 버튼 클릭시
			{
				int clickedX = mouse_x - BLOCK_ORIGIN_X;
				int blockIndex = clickedX / 12;
				addBlock(blockIndex);
				showBlockArray();
			}
			else if (mouse_x >= PS_ORIGIN_X && mouse_x <= PS_ORIGIN_X + 2 * PS_WIDTH + 2 && mouse_y >= PS_ORIGIN_Y && mouse_y <= PS_ORIGIN_Y + PS_HEIGHT) // play버튼 클릭시
			{
				for (int i = 0; i < 24 && blockArray.array[i] != -1; i++)
				{
					executeBlock(i);
					showPC();
					checkEvent();
				}
			}
			else if (mouse_x >= SPEED_ORIGIN_X && mouse_x <= SPEED_ORIGIN_X + 2 * SPEED_WIDTH && mouse_y >= SPEED_ORIGIN_Y && mouse_y <= SPEED_ORIGIN_Y + SPEED_HEIGHT) // speed버튼 클릭시
			{
				changeSpeed();
			}
			else if (mouse_x >= RESET_ORIGIN_X && mouse_x <= RESET_ORIGIN_X + 2 * RESET_WIDTH && mouse_y >= RESET_ORIGIN_Y && mouse_y <= RESET_ORIGIN_Y + RESET_HEIGHT) // reset버튼 클릭시
			{
				resetStage();
			}
			// 블록 배열 삭제
			else if (mouse_x >= BLOCK_ARRAY_ORIGIN_X && mouse_x <= BLOCK_ARRAY_ORIGIN_X + 2 * 36 && mouse_y >= BLOCK_ARRAY_ORIGIN_Y && mouse_y <= BLOCK_ARRAY_ORIGIN_Y + 3 * 6) // straight 버튼 클릭시
			{
				int clickedX = mouse_x - BLOCK_ARRAY_ORIGIN_X;
				int clickedY = mouse_y - BLOCK_ARRAY_ORIGIN_Y;
				int blockIndex = (clickedY / 6 * 6) + (clickedX / 12);
				deleteBlock(blockIndex);
				removeAllBlockArray();
				showBlockArray();
			}
		}
	}	
}