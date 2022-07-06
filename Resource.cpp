#include "DxLib.h"
#include "Resource.h"

int dropPic[6];
int basePic[2];

void LoadPic()
{
	LoadDivGraph("./Resource//Board_PD.png", 2, 2, 1, 100, 100, basePic, true);
	LoadDivGraph("./Resource//Drop_PD.png", 6, 6, 1, 100, 100, dropPic, true);
};

void DeletePic()
{
	
	for (int i = 0; i < 2; i++)
	{
		DeleteGraph(basePic[i]);
	}
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(dropPic[i]);
	}
}