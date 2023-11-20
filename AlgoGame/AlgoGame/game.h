#include "main.h"

#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "block.h"

#endif

#ifndef __MAP_H__
#define __MAP_H__

#include "map.h"

#endif

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "object.h"

#endif

#ifndef UI_INFO
#define UI_INFO

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

#endif

#ifndef GAME_INFO
#define GAME_INFO

#define SPEED_NORMAL 1000
#define SPEED_DOUBLE 500
#define SPEED_TRIPLE 333

#endif

Queue blockArray;
int simulationSpeed = SPEED_NORMAL;
int curStageInfo = 0;
PCInfo player;
int key = 0;
int shield = 0;

void drawScreen();
void drawGameBoard();
void drawBlock();
void drawBlockArray();
void showStageInfo();
void drawPlayStopButton();
void drawResetButton();
void drawExitButton();
void showSpeedButton();
void drawDialogue();
void drawObject(int x, int y, int idx);
void removeMap();
void drawMap();
void showBlockArray();
void clearBlockArray();
void showPC(PCInfo player);
void deletePC(PCInfo player);
void drawUI();

void initBlockArray();
int isBlockArrayFull();
void addBlock(int objectIndex);
void deleteBlock(int arrayIndex);
void changeSpeed();
void emptyBlockArray();
void resetStage();
void goStraight();
void turnLeft();
void turnRight();
void gatherItem();
void useKey();
void useShield();
void usePortal();
void startGame();