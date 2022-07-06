#pragma once
#include <stdlib.h>
#include <stdio.h>

const int cellSize = 100;
const int boardXNum = 6;
const int boardYNum = 5;

extern int isDrag;

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

const int DropBoard[5][6]
{
	{1,4,2,0,4,3},
	{0,0,5,3,3,2},
	{2,0,1,0,2,5},
	{2,4,2,1,1,4},
	{5,0,1,5,5,3},
};

void DrawBase();
void DrawDrop();

void DropChange();

//
//const int board[boardYNum][boardXNum] = 
//{
//	{HI }
//	
//}