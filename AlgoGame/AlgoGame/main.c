#include "main.h"
#pragma warning(disable:4996)

int main()
{	
	init();
	while (1) {
		if (drawTitle())
		{
			setSaveFile();
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
