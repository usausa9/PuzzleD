#include "DxLib.h"
#include "KeyboardInput.h"

// �����o�֐�
char KeyboardInput::keys[256] = { 0 };
char KeyboardInput::prev[256] = { 0 };

// �����o�ϐ�
void KeyboardInput::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		prev[i] = keys[i];
	}

	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

// �L�[�������Ă�����
bool KeyboardInput::GetKey(char key)
{
	return keys[key];
}

// �L�[���������u��
bool KeyboardInput::GetKeyTrigger(char key)
{
	return keys[key] && !prev[key];
}

// �L�[�𗣂����u��
bool KeyboardInput::GetKeyReleased(char key)
{
	return !keys[key] && prev[key];
}

// �����͂�-1,0,1��Ԃ��֐�(speed�ƐώZ����Ə�肭�g����)
int KeyboardInput::GetInputHorizontal()
{
	return (keys[KEY_INPUT_RIGHT] - keys[KEY_INPUT_LEFT]) + (keys[KEY_INPUT_D] - keys[KEY_INPUT_A]);
}

// �c���͂�-1,0,1��Ԃ��֐�(speed�ƐώZ����Ə�肭�g����)
int KeyboardInput::GetInputVertital()
{
	return (keys[KEY_INPUT_DOWN] - keys[KEY_INPUT_UP]) + (keys[KEY_INPUT_S] - keys[KEY_INPUT_W]);
}