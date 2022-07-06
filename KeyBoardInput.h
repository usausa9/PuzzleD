#pragma once

class KeyboardInput
{
	// �����o�֐�
private:
	static char keys[256];
	static char prev[256];

	// �����o�ϐ�
public:
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	static void Update();

	// �L�[�������Ă�����
	static bool GetKey(char key);

	// �L�[���������u��
	static bool GetKeyTrigger(char key);

	// �L�[�𗣂����u��
	static bool GetKeyReleased(char key);

	// �����͂�-1,0,1��Ԃ��֐�(speed�ƐώZ����Ə�肭�g����)
	static int GetInputHorizontal();

	// �c���͂�-1,0,1��Ԃ��֐�(speed�ƐώZ����Ə�肭�g����)
	static int GetInputVertital();
};