#include "DxLib.h"
#include "KeyboardInput.h"

// メンバ関数
char KeyboardInput::keys[256] = { 0 };
char KeyboardInput::prev[256] = { 0 };

// メンバ変数
void KeyboardInput::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		prev[i] = keys[i];
	}

	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}

// キーを押している状態
bool KeyboardInput::GetKey(char key)
{
	return keys[key];
}

// キーを押した瞬間
bool KeyboardInput::GetKeyTrigger(char key)
{
	return keys[key] && !prev[key];
}

// キーを離した瞬間
bool KeyboardInput::GetKeyReleased(char key)
{
	return !keys[key] && prev[key];
}

// 横入力で-1,0,1を返す関数(speedと積算すると上手く使える)
int KeyboardInput::GetInputHorizontal()
{
	return (keys[KEY_INPUT_RIGHT] - keys[KEY_INPUT_LEFT]) + (keys[KEY_INPUT_D] - keys[KEY_INPUT_A]);
}

// 縦入力で-1,0,1を返す関数(speedと積算すると上手く使える)
int KeyboardInput::GetInputVertital()
{
	return (keys[KEY_INPUT_DOWN] - keys[KEY_INPUT_UP]) + (keys[KEY_INPUT_S] - keys[KEY_INPUT_W]);
}