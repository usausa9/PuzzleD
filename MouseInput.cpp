#include "MouseInput.h"
#include "DxLib.h"
#include "Board.h"

MouseInput* MouseInput::GetInstance()
{
	static MouseInput obj;
	return &obj;
}

void MouseInput::Update()
{
	int tempX;
	int tempY;

	// マウスの位置を取得
	GetMousePoint(&tempX, &tempY);

	GetInstance()->x = tempX; 
	GetInstance()->y = tempY;
}

bool MouseInput::GetClick()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) return true;
	else return false;
}

int MouseInput::GetX()
{
	return GetInstance()->x;
}

int MouseInput::GetY()
{
	return GetInstance()->y;
}

int MouseInput::GetMapX()
{
	return GetInstance()->x / cellSize;
}

int MouseInput::GetMapY()
{
	return GetInstance()->y / cellSize;
}

Position MouseInput::GetMapPos()
{
	return { GetInstance()->x / cellSize,GetInstance()->y / cellSize };
}