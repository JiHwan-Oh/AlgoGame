#include "main.h"

#ifndef DIALOGUE_INFO
#define DIALOGUE_INFO

#define STAGE_DIALOGUE_COUNT 30
#define HINT_DIALOGUE_COUNT 7
#define DIALOGUE_CHAR_COUNT 72
#define DIALOGUE_LINE_COUNT 5

#define DIALOGUE_WALL_COLLISION 0
#define DIALOGUE_TRAP_COLLISION 1
#define DIALOGUE_NO_PORTAL		2
#define DIALOGUE_NO_ITEM		3
#define DIALOGUE_NO_KEY			4
#define DIALOGUE_NO_JUMP		5
#define DIALOGUE_DEST_FAILED	6

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
		{ "어떤 블록인지 확인해 봐!" },
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
		{ "달팽이의 등껍질 모양과 닮아 있네." },
		{ "" },
		{ "" }
	},
	// STAGE 1-5
	{
		{ "" },
		{ "" },
		{ "이번엔 계단 모양이야!" },
		{ "" },
		{ "" }
	},
	// STAGE 1-6
	{
		{ "" },
		{ "어라? 두 갈래 길이잖아?" },
		{ "" },
		{ "어느 쪽으로 갈 지는 너의 선택에 달렸어." },
		{ "" }
	},
	// STAGE 1-7
	{
		{ "저 뾰족해 보이는 건 뭘까?" },
		{ "" },
		{ "어쩐지 조금 위험해 보이는 것 같은데..." },
		{ "" },
		{ "아무튼 저기에 닿는 건 피하는 편이 좋아 보여." }
	},
	// STAGE 1-8
	{
		{ "" },
		{ "미로잖아?" },
		{ "" },
		{ "여기서부턴 조심해서 이동하는 게 좋겠어." },
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
		{ "길이 막혀있네." },
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
		{ "별 모양의 벽이라니 특이한걸." },
		{ "" },
		{ "무언가 도구가 필요해 보여." },
		{ "" }
	},
	// STAGE 2-4
	{
		{ "" },
		{ "목표가 바로 앞에 있어." },
		{ "" },
		{ "그런데 어떻게 넘어가야 할까?" },
		{ "" }
	},
	// STAGE 2-5
	{
		{ "" },
		{ "새로운 아이템이야!" },
		{ "" },
		{ "한 번 사용해 볼까?" },
		{ "" }
	},
	// STAGE 2-6
	{
		{ "" },
		{ "" },
		{ "새로운 길을 개척하는 건 용기가 필요해." },
		{ "" },
		{ "" }
	},
	// STAGE 2-7
	{
		{ "" },
		{ "이건 마치 체스판처럼 생겼네." },
		{ "" },
		{ "그런데 왜 한 곳만 일그러져 있는 걸까?" },
		{ "" }
	},
	// STAGE 2-8
	{
		{ "" },
		{ "목표 지점이 완전히 함정으로 가로막혀 있어." },
		{ "" },
		{ "이걸 어떻게 한담?" },
		{ "" }
	},
	// STAGE 2-9
	{
		{ "" },
		{ "장치가 굉장히 많아 보여." },
		{ "" },
		{ "지금까지 배운 것들을 잘 떠올려 보자." },
		{ "" }
	},
	// STAGE 2-10
	{
		{ "" },
		{ "우는 사람의 얼굴 모양과 닮아 보여." },
		{ "" },
		{ "무슨 안 좋은 일이라도 있었던 걸까?" },
		{ "" }
	},
	// STAGE 3-1
	{
		{ "" },
		{ "길이 중간중간 끊어져 있는 것처럼 보이지?" },
		{ "" },
		{ "네가 행동할 때마다 길이 바뀌게 될 거야." },
		{ "" }
	},
	// STAGE 3-2
	{
		{ "" },
		{ "" },
		{ "함정에 빠지지 않기 위해선 끊임없이 움직여야 해." },
		{ "" },
		{ "" }
	},
	// STAGE 3-3
	{
		{ "" },
		{ "" },
		{ "타이밍을 잘 맞춰서 이동해보자." },
		{ "" },
		{ "" }
	},
	// STAGE 3-4
	{
		{ "" },
		{ "" },
		{ "길의 모양을 잘 보고 이동하자." },
		{ "" },
		{ "" }
	},
	// STAGE 3-5
	{
		{ "" },
		{ "" },
		{ "급할수록 돌아가라는 말이 있지." },
		{ "" },
		{ "" }
	},
	// STAGE 3-6
	{
		{ "" },
		{ "" },
		{ "정확한 타이밍에 알맞는 행동을 해야 해." },
		{ "" },
		{ "" }
	},
	// STAGE 3-7
	{
		{ "" },
		{ "" },
		{ "어떻게 해야 저 열쇠를 얻을 수 있을까?" },
		{ "" },
		{ "" }
	},
	// STAGE 3-8
	{
		{ "" },
		{ "" },
		{ "함정의 모양에 유의해서 움직이자." },
		{ "" },
		{ "" }
	},
	// STAGE 3-9
	{
		{ "" },
		{ "가끔은 목표가 하나가 아닐 때도 있지." },
		{ "" },
		{ "어느 목표를 향해 갈 지 잘 선택해야 해." },
		{ "" }
	},
	// STAGE 3-10
	{
		{ "" },
		{ "이제 마지막 단계야." },
		{ "" },
		{ "끝까지 최선을 다해 보자." },
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
	// 아이템 획득 시도 시 해당 칸에 아이템이 없을 때
	{
		{ "" },
		{ "" },
		{ "지금은 획득할 수 있는 아이템이 없어." },
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