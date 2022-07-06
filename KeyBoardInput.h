#pragma once

class KeyboardInput
{
	// メンバ関数
private:
	static char keys[256];
	static char prev[256];

	// メンバ変数
public:
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	static void Update();

	// キーを押している状態
	static bool GetKey(char key);

	// キーを押した瞬間
	static bool GetKeyTrigger(char key);

	// キーを離した瞬間
	static bool GetKeyReleased(char key);

	// 横入力で-1,0,1を返す関数(speedと積算すると上手く使える)
	static int GetInputHorizontal();

	// 縦入力で-1,0,1を返す関数(speedと積算すると上手く使える)
	static int GetInputVertital();
};