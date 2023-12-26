#include "main.h"

MCI_OPEN_PARMS mciOpenBgm;
MCI_PLAY_PARMS mciPlayBgm;
int dwID;

#ifndef RESOURCE_INFO
#define RESOURCE_INFO

#define FILE_PATH "C:\\tmp\\Save.txt"
#define BGM_PATH "C:\\tmp\\BGM.wav"
#define CLICK_SOUND_PATH "C:\\tmp\\Click.mp3"
#define MOVE_SOUND_PATH "C:\\tmp\\Move.mp3"
#define PORTAL_SOUND_PATH "C:\\tmp\\Portal.mp3"
#define COLLECT_SOUND_PATH "C:\\tmp\\ItemCollect.mp3"
#define KEY_SOUND_PATH "C:\\tmp\\Key.mp3"
#define JUMP_SOUND_PATH "C:\\tmp\\Jump.mp3"
#define CLEAR_SOUND_PATH "C:\\tmp\\StageClear.mp3"
#define FAIL_SOUND_PATH "C:\\tmp\\StageFail.mp3"
#define WRONG_SOUND_PATH "C:\\tmp\\Wrong.mp3"

#endif

#ifndef SOUND_INFO
#define SOUND_INFO

#define SOUND_CLICK 0
#define SOUND_MOVE 1
#define SOUND_PORTAL 2
#define SOUND_COLLECT 3
#define SOUND_KEY 4
#define SOUND_JUMP 5
#define SOUND_CLEAR 6
#define SOUND_FAIL 7
#define SOUND_WRONG 8

#endif