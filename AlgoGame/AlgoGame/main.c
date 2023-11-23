#include "main.h"

int main()
{
	init();

	while (1) {
		drawTitle();
		while (1)
		{
			if (drawStageSelect())
				startGame();
			else
				break;
		}
	}
	

	SetCurrentCursorPos(0, 42);
	printf("\n\n\n\n\n");

	return 0;
}
