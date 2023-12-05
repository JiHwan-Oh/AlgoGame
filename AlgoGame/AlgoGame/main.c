#include "main.h"
#pragma warning(disable:4996)
#pragma comment (lib, "winmm.lib")

int main()
{	
	init();
	while (1) {
		if (drawTitle())
		{
			system("cls");
			return 0;
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
