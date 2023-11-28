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
				startStage();
			else
				break;
		}
	}
	return 0;
}
