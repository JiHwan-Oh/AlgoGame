#include "main.h"

int main()
{
	init();
	drawTitle();
	startGame();

	/*
	while (1) {
		
		// drawTitle();
		
		int menuCode = drawTitleMenu();
		switch (menuCode) {
		case 0:	// 게임 시작
			// drawStageSelect();
			break;
		case 1:	// 게임 방법
			// drawManual();
			break;
		case 2:	// 게임 종료
			return 0;
			break;
		}
	}
	*/

	SetCurrentCursorPos(0, 42);
	printf("\n\n\n\n\n");

	return 0;
}
