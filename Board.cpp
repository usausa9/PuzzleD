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

void DrawDrop()
{
	for (int x = 0; x < boardXNum; x++)
	{
		for (int y = 0; y < boardYNum; y++)
		{
			int DropBoardDate = DropBoard[y][x];

			if (DropBoardDate == 0)
			{
				DrawGraph(100 * x, 100 * y, dropPic[0], true);
			}
			if (DropBoardDate == 1)
			{
				DrawGraph(100 * x, 100 * y, dropPic[1], true);
			}
			if (DropBoardDate == 2)
			{
				DrawGraph(100 * x, 100 * y, dropPic[2], true);
			}
			if (DropBoardDate == 3)
			{
				DrawGraph(100 * x, 100 * y, dropPic[3], true);
			}
			if (DropBoardDate == 4)
			{
				DrawGraph(100 * x, 100 * y, dropPic[4], true);
			}
			if (DropBoardDate == 5)
			{
				DrawGraph(100 * x, 100 * y, dropPic[5], true);
			}
		}
	}
};

void DropChange()
{

}