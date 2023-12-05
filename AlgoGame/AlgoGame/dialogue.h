#include "main.h"

#ifndef DIALOGUE_INFO
#define DIALOGUE_INFO

#define STAGE_DIALOGUE_COUNT 30
#define HINT_DIALOGUE_COUNT 6
#define DIALOGUE_CHAR_COUNT 72
#define DIALOGUE_LINE_COUNT 5

#define DIALOGUE_WALL_COLLISION 0
#define DIALOGUE_TRAP_COLLISION 1
#define DIALOGUE_NO_PORTAL		2
#define DIALOGUE_NO_KEY			3
#define DIALOGUE_NO_JUMP		4
#define DIALOGUE_DEST_FAILED	5

#endif

char stageDialogue[STAGE_DIALOGUE_COUNT][DIALOGUE_LINE_COUNT][DIALOGUE_CHAR_COUNT + 1] = {
	// STAGE 1-1
	{
		{ "알고리즘 스쿨에 어서와!" },
		{ "우선 화면 왼쪽 아래에 있는" },
		{ "화살표 모양 블록을 클릭해 추가해 봐." },
		{ "그리고 화면 오른쪽 위의 PLAY 버튼을 눌러서" },
		{ "빨간색으로 표시된 곳까지 이동해 봐!" }
	},
	// STAGE 1-2
	{
		{ "" },
		{ "새로운 블록이 추가된 것 같은데?" },
		{ "" },
		{ "이건 어떤 블록일까?" },
		{ "" }
	},
	// STAGE 1-3
	{
		{ "" },
		{ "이번엔 오른쪽 화살표 모양이네!" },
		{ "" },
		{ "유용하게 활용할 수 있겠는걸?" },
		{ "" }
	},
	// STAGE 1-4
	{
		{ "" },
		{ "" },
		{ "이건... 달팽이인가?" },
		{ "" },
		{ "" }
	},
	// STAGE 1-5
	{
		{ "" },
		{ "" },
		{ "이건 계단 모양 같기도 하고..." },
		{ "" },
		{ "" }
	},
	// STAGE 1-6
	{
		{ "" },
		{ "어라? 두 갈래 길이잖아?" },
		{ "" },
		{ "음... 어느 쪽으로 가야 할까?" },
		{ "" }
	},
	// STAGE 1-7
	{
		{ "" },
		{ "저 뾰족해 보이는 건 뭘까?" },
		{ "어쩐지 조금 위험해 보이는 것 같은데..." },
		{ "아무튼 저기에 닿는 건 피해야겠어." },
		{ "" }
	},
	// STAGE 1-8
	{
		{ "" },
		{ "" },
		{ "미로잖아? 조심해서 이동하는 게 좋겠어..." },
		{ "" },
		{ "" }
	},
	// STAGE 1-9
	{
		{ "" },
		{ "미로를 탈출했더니 더 복잡한 미로라니..." },
		{ "" },
		{ "당황하지 말고 천천히 길을 찾아보자." },
		{ "" }
	},
	// STAGE 1-10
	{
		{ "목표가 엄청 멀잖아...?" },
		{ "무작정 움직이다가는" },
		{ "도착하기도 전에 힘을 다 써버릴 것 같은걸..." },
		{ "가끔은 앞만 보고 달리지 않는 자세가 필요해." },
		{ "" }
	},
	// STAGE 2-1
	{
		{ "" },
		{ "길이 막혀있잖아...?" },
		{ "" },
		{ "어떻게 하면 저 너머로 갈 수 있을까?" },
		{ "" }
	},
	// STAGE 2-2
	{
		{ "" },
		{ "" },
		{ "목표에 빠르게 도달할 방법을 찾아보자." },
		{ "" },
		{ "" }
	},
	// STAGE 2-3
	{
		{ "" },
		{ "별 모양의 벽이라니... 특이한걸." },
		{ "" },
		{ "무언가 도구가 필요해 보여." },
		{ "" }
	},
	// STAGE 2-4
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	},
	// STAGE 2-5
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	},
	// STAGE 2-6
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	},
	// STAGE 2-7
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	},
	// STAGE 2-8
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	},
	// STAGE 2-9
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	},
	// STAGE 2-10
	{
		{ "" },
		{ "" },
		{ "" },
		{ "" },
		{ "" }
	}
};

char hintDialogue[HINT_DIALOGUE_COUNT][DIALOGUE_LINE_COUNT][DIALOGUE_CHAR_COUNT + 1] = {
	// 벽에 가로막혀 이동할 수 없을 때
	{
		{ "" },
		{ "" },
		{ "벽으로 가로막혀 있어서 이동할 수 없어." },
		{ "" },
		{ "" }
	},
	// 함정으로 인해 스테이지를 실패했을 때
	{
		{ "" },
		{ "함정에 걸려버렸어..." },
		{ "" },
		{ "다른 방법을 찾아보자." },
		{ "" }
	},
	// 포탈 이외의 칸에서 포탈을 사용했을 때
	{
		{ "" },
		{ "" },
		{ "여기선 포탈을 사용할 수 없어." },
		{ "" },
		{ "" }
	},
	// 열쇠 아이템 사용 시 소지한 열쇠가 없을 때
	{
		{ "" },
		{ "" },
		{ "지금은 가진 열쇠가 없어." },
		{ "" },
		{ "" }
	},
	// 점프 아이템 사용 시 소지한 점프가 없을 때
	{
		{ "" },
		{ "" },
		{ "점프 아이템이 부족해." },
		{ "" },
		{ "" }
	},
	// 도착점에 도달하지 못했을 때
	{
		{ "" },
		{ "목표에 도달하지 못했어." },
		{ "" },
		{ "뭔가 방법이 있을 것 같은데..." },
		{ "" }
	}
};