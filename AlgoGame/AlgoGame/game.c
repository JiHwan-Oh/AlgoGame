#include "game.h"

void removeAll()
{
	for (int i = 2; i < 152; i++)
		for (int j = 1; j < 46; j++)
		{
			SetCurrentCursorPos(i, j);
			printf(" ");
		}
}

void drawTitleButton()
{
	int chapx = 25;
	int chapy = 10;
	int color[9] = { 4, 6, 14, 10, 11, 9, 5, 7, 15 };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[j]);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			for (int x = 0; x < 5; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					SetCurrentCursorPos(chapx + (x * 2), chapy + y);
					if (title[i][j][y][x] == 1)
						printf("■");
				}
			}
			chapx += 12;
		}
		chapx = 42;
		chapy += 6;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetCurrentCursorPos(62, 23);
	printf("마우스로 클릭하여 시작하세요!!");
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

	for (y = 0; y <= TERMINATE_HEIGHT; y++)
	{
		SetCurrentCursorPos(TERMINATE_ORIGIN_X, TERMINATE_ORIGIN_Y + y);
		if (y == TERMINATE_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= TERMINATE_HEIGHT; y++)
	{
		SetCurrentCursorPos(TERMINATE_ORIGIN_X + (TERMINATE_WIDTH + 1) * 2, TERMINATE_ORIGIN_Y + y);
		if (y == TERMINATE_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < TERMINATE_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(TERMINATE_ORIGIN_X + x * 2, TERMINATE_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < TERMINATE_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(TERMINATE_ORIGIN_X + x * 2, TERMINATE_ORIGIN_Y + TERMINATE_HEIGHT);
		printf("━");
	}
	int terminateX = TERMINATE_ORIGIN_X + 8;
	int terminateY = TERMINATE_ORIGIN_Y + 2;
	SetCurrentCursorPos(terminateX, terminateY);
	printf("게임종료");
}

int drawTitle()
{
	BasicSetting();
	drawScreen();
	drawTitleButton();
	while (1)
	{
		drawTitleButton();
		int m = CheckMouse();
		if (m == 1)
		{
			if (mouse_x >= START_ORIGIN_X && mouse_x <= START_ORIGIN_X + 2 * START_WIDTH && mouse_y >= START_ORIGIN_Y && mouse_y <= START_ORIGIN_Y + START_HEIGHT) // start 버튼 클릭시
			{
				removeAll();
				return 0;
			}
			else if (mouse_x >= MANUAL_ORIGIN_X && mouse_x <= MANUAL_ORIGIN_X + 2 * MANUAL_WIDTH && mouse_y >= MANUAL_ORIGIN_Y && mouse_y <= MANUAL_ORIGIN_Y + MANUAL_HEIGHT) // manual 버튼 클릭시
			{
				removeAll();
				if (drawManual())
				{
					removeAll();
					continue;;
				}
				return 0;
			}
			else if (mouse_x >= TERMINATE_ORIGIN_X && mouse_x <= TERMINATE_ORIGIN_X + 2 * TERMINATE_WIDTH && mouse_y >= TERMINATE_ORIGIN_Y && mouse_y <= TERMINATE_ORIGIN_Y + TERMINATE_HEIGHT) // manual 버튼 클릭시
			{
				removeAll();
				return 1;
			}
		}
	}
}

int drawManual()
{
	drawScreen();
	int x, y;
	int blockPosX = 6;
	int blockPosY = 5;
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
		blockPosY += 6;
	}
	SetCurrentCursorPos(6, 2); 
	printf("→ : 화살표가 플레이어 캐릭터 입니다. 화살표가 가리키는 방향이 플레이어가 바라보는 방향입니다.");
	SetCurrentCursorPos(6, 3);
	printf("     아래에 있는 명령블록들을 이용해 캐릭터를 움직일 수 있습니다.");

	SetCurrentCursorPos(18, 7); // 전진
	printf(": 캐릭터가 바라보는 방향으로 한 칸 전진합니다.   예)                  >>>");
	drawObject(74, 6, 1); drawObject(80, 6, 1); drawObject(94, 6, 1); drawObject(100, 6, 1);
	SetCurrentCursorPos(76, 7); printf("→"); SetCurrentCursorPos(102, 7); printf("→");

	SetCurrentCursorPos(18, 13); // 좌측
	printf(": 캐릭터가 왼쪽을 바라보게 합니다.   예) 캐릭터가 → 였다면 이 명령블록 사용후 캐릭터는 ↑ 이 됩니다.");
	SetCurrentCursorPos(18, 19); // 우측
	printf(": 캐릭터가 오른쪽을 바라보게 합니다.   예) 캐릭터가 → 였다면 이 명령블록 사용후 캐릭터는 ↓ 이 됩니다.");

	SetCurrentCursorPos(18, 25); // 아이템 획득
	printf(": 캐릭터가 위치한 칸에 있는 아이템을 획득합니다.        예)  열쇠 :             점프:");
	SetCurrentCursorPos(18, 26); 
	printf("  화면 우측 상단에 보유한 아이템 갯수가 표시됩니다.");
	drawObject(86, 24, 5); drawObject(104, 24, 6);
	SetCurrentCursorPos(88, 25); printf("→"); SetCurrentCursorPos(106, 25); printf("→");

	SetCurrentCursorPos(18, 31); // key 사용
	printf(": 캐릭터가 위치한 칸의 상하좌우 칸이 벽일 경우 지나갈 수 있는 길로 주변 칸을 변경합니다.      예)                >>>");
	drawObject(120, 31, 1); drawObject(120, 28, 4); drawObject(140, 31, 1); drawObject(140, 28, 1);
	SetCurrentCursorPos(122, 32); printf("↑"); SetCurrentCursorPos(142, 32); printf("↑");

	SetCurrentCursorPos(18, 37); // shield 사용
	printf(": 캐릭터가 바로 다음 전진하는 칸이 가시밭 길 이더라도 캐릭터가 죽지 않습니다.       예)                    >>>");
	drawObject(110, 36, 1); drawObject(116, 36, 2); drawObject(130, 36, 1); drawObject(136, 36, 2);
	SetCurrentCursorPos(112, 37); printf("→"); SetCurrentCursorPos(138, 37); printf("→");

	SetCurrentCursorPos(18, 43); // portal 사용
	printf(": 캐릭터가 포탈 칸에 있을 때 사용할 경우. 다른 포탈 칸으로 캐릭터를 이동시킵니다.    예)");
	drawObject(110, 42, 1); drawObject(116, 42, 3); drawObject(130, 42, 3); drawObject(136, 42, 1);
	SetCurrentCursorPos(118, 43); printf("→"); SetCurrentCursorPos(132, 43); printf("→");

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
	while (1)
	{
		int m = CheckMouse();
		if (m == 1)
		{
			if (mouse_x >= MANUAL_BACK_ORIGIN_X && mouse_x <= MANUAL_BACK_ORIGIN_X + 2 * MANUAL_BACK_WIDTH && mouse_y >= MANUAL_BACK_ORIGIN_Y && mouse_y <= MANUAL_BACK_ORIGIN_Y + MANUAL_BACK_HEIGHT) // 듀토리얼에서 뒤로가기 버튼 클릭시
			{
				removeAll();
				return 1;
			}
		}
	}
}

int drawStageSelect()
{
	drawScreen();
	SetCurrentCursorPos(12, 5);
	printf("스테이지를 선택하세요!!");
	int chapx = 50;
	int chapy = 3;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		if (i == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			chapx -= 6;
		}
		if (i == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		}
		for (int j = 0; j < 6; j++)
		{
			for (int x = 0; x < 5; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					SetCurrentCursorPos(chapx + (x * 2), chapy + y);
					if (chapter[i][j][y][x] == 1)
						printf("■");
				}
			}
			chapx += 12;
		}
		chapx = 50;
		chapy += 14;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int x, y, plusx = 14, plusy = 14;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		else if (i == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		else if (i == 2)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		for (int j = 0; j < 10; j++)
		{
			SetCurrentCursorPos(SELECT_ORIGIN_X + plusx * j + 6, SELECT_ORIGIN_Y + plusy * i + 1);
			printf("%d", j + 1);
			SetCurrentCursorPos(SELECT_ORIGIN_X + plusx * j + 3, SELECT_ORIGIN_Y + plusy * i + 3);
			if (clearmap[10 * i + j] == 0)
				printf("☆ ☆ ☆");
			else
				printf("★ ★ ★");
			for (y = 0; y <= SELECT_HEIGHT; y++)
			{
				SetCurrentCursorPos(SELECT_ORIGIN_X + plusx * j, SELECT_ORIGIN_Y + y + plusy * i);
				if (y == SELECT_HEIGHT)
					printf("┗");
				else if (y == 0)
					printf("┏");
				else
					printf("┃");
			}
			for (y = 0; y <= SELECT_HEIGHT; y++)
			{
				SetCurrentCursorPos(SELECT_ORIGIN_X + (SELECT_WIDTH + 1) * 2 + plusx * j, SELECT_ORIGIN_Y + y + plusy * i);
				if (y == SELECT_HEIGHT)
					printf("┛");
				else if (y == 0)
					printf("┓");
				else
					printf("┃");
			}
			for (x = 1; x < SELECT_WIDTH + 1; x++)
			{
				SetCurrentCursorPos(SELECT_ORIGIN_X + x * 2 + plusx * j, SELECT_ORIGIN_Y + plusy * i);
				printf("━");
			}
			for (x = 1; x < SELECT_WIDTH + 1; x++)
			{
				SetCurrentCursorPos(SELECT_ORIGIN_X + x * 2 + plusx * j, SELECT_ORIGIN_Y + SELECT_HEIGHT + plusy * i);
				printf("━");
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (y = 0; y <= SELECT_BACK_HEIGHT; y++)
	{
		SetCurrentCursorPos(SELECT_BACK_ORIGIN_X, SELECT_BACK_ORIGIN_Y + y);
		if (y == SELECT_BACK_HEIGHT)
			printf("┗");
		else if (y == 0)
			printf("┏");
		else
			printf("┃");
	}
	for (y = 0; y <= SELECT_BACK_HEIGHT; y++)
	{
		SetCurrentCursorPos(SELECT_BACK_ORIGIN_X + (SELECT_BACK_WIDTH + 1) * 2, SELECT_BACK_ORIGIN_Y + y);
		if (y == SELECT_BACK_HEIGHT)
			printf("┛");
		else if (y == 0)
			printf("┓");
		else
			printf("┃");
	}
	for (x = 1; x < SELECT_BACK_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(SELECT_BACK_ORIGIN_X + x * 2, SELECT_BACK_ORIGIN_Y);
		printf("━");
	}
	for (x = 1; x < SELECT_BACK_WIDTH + 1; x++)
	{
		SetCurrentCursorPos(SELECT_BACK_ORIGIN_X + x * 2, SELECT_BACK_ORIGIN_Y + SELECT_BACK_HEIGHT);
		printf("━");
	}
	int backX = SELECT_BACK_ORIGIN_X + 8;
	int backY = SELECT_BACK_ORIGIN_Y + 2;
	SetCurrentCursorPos(backX, backY);
	printf("뒤로가기");
	while (1)
	{
		int m = CheckMouse();

		if (m == 1)
		{
			if (mouse_x >= SELECT_BACK_ORIGIN_X && mouse_x <= SELECT_BACK_ORIGIN_X + 2 * SELECT_BACK_WIDTH && mouse_y >= SELECT_BACK_ORIGIN_Y && mouse_y <= SELECT_BACK_ORIGIN_Y + SELECT_BACK_HEIGHT) // start 버튼 클릭시
			{
				removeAll();
				return 0;
			}

			// 스테이지 선택
			if (mouse_x >= SELECT_ORIGIN_X && mouse_x <= SELECT_ORIGIN_X + 28 * SELECT_WIDTH && mouse_y >= SELECT_ORIGIN_Y && mouse_y <= SELECT_ORIGIN_Y + SELECT_HEIGHT) // easy 스테이지 버튼 클릭시
			{
				int clickedX = mouse_x - SELECT_ORIGIN_X;
				curStageInfo = clickedX / 14;
				removeAll();
				return 1;
			}
			else if (mouse_x >= SELECT_ORIGIN_X && mouse_x <= SELECT_ORIGIN_X + 28 * SELECT_WIDTH && mouse_y >= SELECT_ORIGIN_Y + 14 && mouse_y <= SELECT_ORIGIN_Y + SELECT_HEIGHT + 14) // normal 스테이지 버튼 클릭시
			{
				int clickedX = mouse_x - SELECT_ORIGIN_X;
				curStageInfo = clickedX / 14 + 10;
				removeAll();
				return 1;
			}
			else if (mouse_x >= SELECT_ORIGIN_X && mouse_x <= SELECT_ORIGIN_X + 28 * SELECT_WIDTH && mouse_y >= SELECT_ORIGIN_Y + 28 && mouse_y <= SELECT_ORIGIN_Y + SELECT_HEIGHT + 28) // hard 스테이지 버튼 클릭시
			{
				int clickedX = mouse_x - SELECT_ORIGIN_X;
				curStageInfo = clickedX / 14 + 20;
				removeAll();
				return 1;
			}
		}
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
	for (int i = 0; i < blockLimit[curStageInfo]; i++)
	{
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
	printf("KEY : %d        JUMP : %d", key, jump);
}

void drawBlockCountInfo() {
	int infoX = INFO_ORIGIN_X + 2;
	int infoY = INFO_ORIGIN_Y + 1;
	SetCurrentCursorPos(infoX, infoY + 7);
	printf("                          ");
	SetCurrentCursorPos(infoX, infoY + 7);
	printf("[COMMAND BLOCK COUNT] : %d", blockCount);
}

void drawStageInfo()
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
	printf("[CHAPTER] :   , [STAGE] :   ");
	SetCurrentCursorPos(infoX, infoY);
	printf("[CHAPTER] : %d, [STAGE] : %d", curStageInfo / 10 + 1, curStageInfo % 10 + 1);
	SetCurrentCursorPos(infoX, infoY + 3);
	printf("[ITEM]");
	drawItemInfo();
	drawBlockCountInfo();
}

void drawPlayButton()
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

void drawSpeedButton()
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
	switch (speed)
	{
	case 1:
		printf("▶    ");
		break;
	case 2:
		printf("▶▶  ");
		break;
	case 3:
		printf("▶▶▶");
		break;
	default:
		break;
	}
	speedY += 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("%d배속", speed);
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
				printf("♤");
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
			int index = curMap[i][j];
			if (index == 7) // 도착점 빨간색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			drawObject(x + (6 * j), y + (3 * i), index);
		}
}

void showBlockArray(int idx)
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
				{
					if (i == idx)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						printf("■");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						continue;
					}
					printf("■");
				}
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
	drawStageInfo();
	drawPlayButton();
	drawResetButton();
	drawDialogue();
	drawExitButton();
	drawSpeedButton();
	drawMap();
}

// Stage 모듈

void loadMapInfo() {
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			curMap[i][j] = map[curStageInfo][i][j];
}

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
	speedY += 2;
	SetCurrentCursorPos(speedX, speedY);
	printf("%d배속", speed);
}

void resetBlockArray()
{
	initBlockArray();
	removeAllBlockArray();
	showBlockArray(999);
}

void resetPlayer() {
	player = initialPCPos[curStageInfo];
	showPC();
}

void resetItem() {
	key = 0;
	jump = 0;
	drawItemInfo();
}

void resetBlockCount() {
	blockCount = 0;
	drawBlockCountInfo();
}

// 스테이지 재시작 함수
void resetStage()
{
	removeMap();
	loadMapInfo();
	drawMap();
	resetPlayer();
	resetItem();
	resetBlockCount();
	resetBlockArray();
}

void hitMoment()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (4 << 4) + 15);
	for (int i = 0; i < GBOARD_HEIGHT-1; i++)
	{
		SetCurrentCursorPos(4, i + 2);
		printf("                                                                        ");
	}
	Sleep(50);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < GBOARD_HEIGHT - 1; i++)
	{
		SetCurrentCursorPos(4, i + 2);
		printf("                                                                        ");
	}
}
// 시뮬레이션 종료 함수
void stopSimulation() {
	removeMap();
	loadMapInfo();
	drawMap();
	resetPlayer();
	resetItem();
	showBlockArray(999);
}

// 오브젝트 블록 기능 수행 함수
void goStraight()
{
	deletePC();
	if (!checkWall(1)) {
		
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
	else {
		// PC 색상을 빨간색으로 잠시 변경 후 다시 원래 색으로 되돌림
		int x = GBOARD_ORIGIN_X + 4;
		int y = GBOARD_ORIGIN_Y + 2;
		SetCurrentCursorPos(x + (6 * player.x), y + (3 * player.y));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		deletePC();
		// $$ 앞이 벽이라 지나갈 수 없다는 Dialogue 출력
	}
	showPC();
}

void turnLeft()
{
	deletePC();
	player.dir = (player.dir + 3) % 4;
	showPC();
}

void turnRight()
{
	deletePC();
	player.dir = (player.dir + 5) % 4;
	showPC();
}

void gatherItem()
{
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (curMap[player.y][player.x] == 5)
	{
		key++;
	}
	else if (curMap[player.y][player.x] == 6)
	{
		jump++;
	}
	else
		return;
	drawObject(x + (6 * player.x), y + (3 * player.y), 1);
	showPC();
	drawItemInfo();
}

void usePortal()
{
	if (curMap[player.y][player.x] == 3)	// 현재 위치가 포탈인 경우
	{
		int isTeleported = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (curMap[i][j] == 3 && !(player.x == j && player.y == i))
				{
					deletePC();
					player.x = j;
					player.y = i;
					showPC();
					isTeleported = 1;
					break;
				}
			}
			if (isTeleported)
				break;
		}
	}
}

void useKey()
{
	if (key == 0)
		return;
	int x = GBOARD_ORIGIN_X + 2;
	int y = GBOARD_ORIGIN_Y + 1;
	if (curMap[player.y][player.x - 1] == 4) // 좌측 칸이 자물쇠인 경우
	{
		curMap[player.y][player.x - 1] = 1;
		drawObject(x + (6 * (player.x - 1)), y + (3 * player.y), 1);
	}
	else if (curMap[player.y][player.x + 1] == 4) // 우측 칸이 자물쇠인 경우
	{
		curMap[player.y][player.x + 1] = 1;
		drawObject(x + (6 * (player.x + 1)), y + (3 * player.y), 1);
	}
	else if (curMap[player.y - 1][player.x] == 4) // 위 칸이 자물쇠인 경우
	{
		curMap[player.y - 1][player.x] = 1;
		drawObject(x + (6 * player.x), y + (3 * (player.y - 1)), 1);
	}
	else if (curMap[player.y + 1][player.x] == 4) // 아래 칸이 자물쇠인 경우
	{
		curMap[player.y + 1][player.x] = 1;
		drawObject(x + (6 * player.x), y + (3 * (player.y + 1)), 1);
	}
	showPC();
	key--;
	drawStageInfo();
}

void useJump()
{
	if (jump == 0)
		return;
	deletePC();
	if (!checkWall(2)) {
		switch (player.dir)
		{
		case 0:
			player.y -= 2;
			break;
		case 1:
			player.x += 2;
			break;
		case 2:
			player.y += 2;
			break;
		case 3:
			player.x -= 2;
			break;
		default:
			break;
		}
	}
	showPC();
	jump--;
	drawStageInfo();
}

// 블록 기능 수행
void executeBlock(int index)
{
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
		usePortal();
		break;
	case 4:
		gatherItem();
		break;
	case 5:
		useKey();
		break;
	case 6:
		useJump();
		break;
	case 7:
		break;
	default:
		break;
	}
}

// 스테이지 클리어 조건을 만족(도착점에 도달)했다면 1, 만족하지 않았다면 0 반환
int checkStageClear()
{
	if (curMap[player.y][player.x] == 7) {
		return 1;
	}
	return 0;
}

int checkWall(int distance)
{
	int nextPosX = player.x;
	int nextPosY = player.y;

	switch (player.dir) {
	case 0:
		nextPosY -= distance;
		break;
	case 1:
		nextPosX += distance;
		break;
	case 2:
		nextPosY += distance;
		break;
	case 3:
		nextPosX -= distance;
		break;
	default:
		break;
	}

	if (curMap[nextPosY][nextPosX] == 0 || curMap[nextPosY][nextPosX] == 4 || nextPosX < 0 || nextPosX >= 12 || nextPosY < 0 || nextPosY >= 12)
		return 1;
	return 0;
}

// 함정과 충돌했다면 1 반환, 충돌하지 않았다면 0 반환
int checkTrap()
{
	if (curMap[player.y][player.x] == 2) // 현재 위치가 함정일 경우
		return 1;
	return 0;
}

// 포탈과 충돌했다면 1 반환, 충돌하지 않았다면 0 반환
int checkPortal()
{
	if (curMap[player.y][player.x] == 3) // 현재 위치가 포탈인 경우
		return 1;
	return 0;
}

int checkEvent()
{
	if (checkStageClear()) return EVENT_STAGE_CLEAR;
	if (checkTrap()) return EVENT_TRAP;
	return EVENT_NONE;
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

// 스테이지 시작 함수
void startStage() {
	BasicSetting();
	initBlockArray();
	loadMapInfo();
	drawUI();
	player = initialPCPos[curStageInfo];
	showBlockArray(999);
	showPC();
	while (1)
	{
		int m = CheckMouse();
		if (m == 1)
		{
			if (mouse_x >= BLOCK_ORIGIN_X && mouse_x <= BLOCK_ORIGIN_X + 2 * BLOCK_WIDTH && mouse_y >= BLOCK_ORIGIN_Y && mouse_y <= BLOCK_ORIGIN_Y + BLOCK_HEIGHT) // 블록 버튼 클릭시
			{
				int clickedX = mouse_x - BLOCK_ORIGIN_X;
				int blockIndex = clickedX / 12;
				if (blockIndex < blockLimit[curStageInfo]) {
					addBlock(blockIndex);
					removeAllBlockArray();
					showBlockArray(999);
				}
			}
			else if (mouse_x >= BLOCK_ARRAY_ORIGIN_X && mouse_x <= BLOCK_ARRAY_ORIGIN_X + 2 * BLOCK_ARRAY_WIDTH && mouse_y >= BLOCK_ARRAY_ORIGIN_Y && mouse_y <= BLOCK_ARRAY_ORIGIN_Y + BLOCK_ARRAY_HEIGHT) // 블록 배열 클릭시 삭제
			{
				int clickedX = mouse_x - BLOCK_ARRAY_ORIGIN_X;
				int clickedY = mouse_y - BLOCK_ARRAY_ORIGIN_Y;
				int blockArrayIndex = clickedX / 12 + clickedY / 6 * 6;
				if (blockArrayIndex >= 0 && blockArrayIndex < 24 && blockArray.array[blockArrayIndex] != -1) {
					deleteBlock(blockArrayIndex);
					removeAllBlockArray();
					showBlockArray(999);
				}
			}
			else if (mouse_x >= PS_ORIGIN_X && mouse_x <= PS_ORIGIN_X + 2 * PS_WIDTH + 2 && mouse_y >= PS_ORIGIN_Y && mouse_y <= PS_ORIGIN_Y + PS_HEIGHT) // play버튼 클릭시
			{
				int event = -1;
				for (int i = 0; i < 24 && blockArray.array[i] != -1; i++)
				{
					executeBlock(i);
					showBlockArray(i);	
					Sleep(simulationSpeed);
					event = checkEvent();
					if (event == EVENT_STAGE_CLEAR) // 스테이지 클리어 시 StageClear 화면 출력, 맵 초기화 후 현재 명령 블록 수행 종료
					{
						// StageClear 화면 출력
						clearmap[curStageInfo] = 1;
						curStageInfo++;
						drawStageInfo();
						drawBlock();
						resetStage();
						break;
					}
					else if (event == EVENT_TRAP)	// 함정 충돌 시 현재 시뮬레이션 종료 후 현재 명령 블록 수행 종료
					{
						hitMoment();
						stopSimulation();
						break;
					}
					if (blockArray.array[i + 1] == -1 || i + 1 == 24)
						showBlockArray(999);
				}
				if (event != EVENT_STAGE_CLEAR && event != EVENT_TRAP)	// 명령 블록을 모두 수행한 후에도 스테이지를 클리어하지 못했다면 시뮬레이션 종료
				{
					stopSimulation();
					// $$ 목표 지점에 도달하지 못했다는 Dialogue 출력
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
			else if (mouse_x >= BACK_ORIGIN_X && mouse_x <= BACK_ORIGIN_X + 2 * BACK_WIDTH && mouse_y >= BACK_ORIGIN_Y && mouse_y <= BACK_ORIGIN_Y + BACK_HEIGHT) // exit버튼 클릭시
			{
				resetBlockCount();
				resetItem();
				removeAll();
				return;
			}
		}
	}	
}