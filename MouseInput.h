#pragma once

struct Position
{
	int x;
	int y;
};

class MouseInput
{
	// メンバ関数
public:
	int x = 0;
	int y = 0;

	// メンバ変数
public:

	static MouseInput* GetInstance();

	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	static void Update();

	// キーを押している状態
	static bool GetClick();

	static int GetX();

	static int GetY();

	static int GetMapX();
	static int GetMapY();

	static Position GetBoardPos();

	//// キーを押した瞬間
	//static bool GetKeyTrigger(char key);

	//// キーを離した瞬間
	//static bool GetKeyReleased(char key);

	//// 横入力で-1,0,1を返す関数(speedと積算すると上手く使える)
	//static int GetInputHorizontal();

	//// 縦入力で-1,0,1を返す関数(speedと積算すると上手く使える)
	//static int GetInputVertital();
};