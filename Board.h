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

const int BaseMap[boardYNum][boardXNum]
{
	{0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,1,0,1,0,1},
};

extern int DropBoard[boardYNum][boardXNum];

void DrawBase();
void DrawDrop();

void DropChange();