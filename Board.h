#pragma once
#include <stdlib.h>
#include <stdio.h>

const int cellSize = 100;
const int boardXNum = 6;
const int boardYNum = 5;

enum DropDate
{
	HI,
	MIZU,
	KI,
	HIKARI,
	YAMI,
	KAIHUKU,

	kMaxDate
};

const int BaseMap[5][6]
{
	{0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,1,0,1,0,1},
};

void DrawBase();

//
//const int board[boardYNum][boardXNum] = 
//{
//	{HI }
//	
//}