#include "Board.h"
#include "DxLib.h"
#include "Resource.h"
#include "MouseInput.h"

int isDrag = false;

int DropBoard[boardYNum][boardXNum]
{
	{1,4,2,0,4,3},
	{0,0,5,3,3,2},
	{2,0,1,0,2,5},
	{2,4,2,1,1,4},
	{5,0,1,5,5,3},
};

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
	Position grabDrop = MouseInput::GetBoardPos();

	if (MouseInput::GetClick() == 1)
	{
		isDrag = true;
	}
	if (MouseInput::GetClick() == 0)
	{
		isDrag = false;
	}

	if (grabDrop.x != MouseInput::GetBoardPos().x || grabDrop.y != MouseInput::GetBoardPos().y)
	{
		int stayDate;
		stayDate = DropBoard[MouseInput::GetBoardPos().y][MouseInput::GetBoardPos().x];

		DropBoard[MouseInput::GetBoardPos().y][MouseInput::GetBoardPos().x] = DropBoard[grabDrop.y][grabDrop.x];
		DropBoard[grabDrop.y][grabDrop.x] = stayDate;
	}

	if (isDrag == 1)
	{
		grabDrop = MouseInput::GetBoardPos();
	}
}