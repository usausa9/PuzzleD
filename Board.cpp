#include "Board.h"
#include "DxLib.h"
#include "Resource.h"

void DrawBase()
{
	for (int x = 0; x < boardXNum; x++)
	{
		for (int y = 0; y < boardYNum; y++)
		{
			int baseMapDate = BaseMap[y][x];

			if (baseMapDate == 0)
			{
				DrawGraph(100 * x, 100 * y, basePic[0], true);
			}
			if (baseMapDate == 1)
			{
				DrawGraph(100 * x, 100 * y, basePic[1], true);
			}
		}
	}
};