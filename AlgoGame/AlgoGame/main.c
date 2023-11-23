#include "main.h"

int main()
{
	init();

	while (1) {
		if (drawTitle())
		{
			system("cls");
			return;
		}
		while (1)
		{
			if (drawStageSelect())
				startGame();
			else
				break;
		}
	}


	SetCurrentCursorPos(20, 20);

	return 0;
}
