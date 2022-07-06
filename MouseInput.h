#pragma once

struct Position
{
	int x;
	int y;
};

class MouseInput
{
	// �����o�֐�
public:
	int x = 0;
	int y = 0;

	// �����o�ϐ�
public:

	static MouseInput* GetInstance();

	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	static void Update();

	// �L�[�������Ă�����
	static bool GetClick();

	static int GetX();

	static int GetY();

	static int GetMapX();
	static int GetMapY();

	static Position GetBoardPos();

	//// �L�[���������u��
	//static bool GetKeyTrigger(char key);

	//// �L�[�𗣂����u��
	//static bool GetKeyReleased(char key);

	//// �����͂�-1,0,1��Ԃ��֐�(speed�ƐώZ����Ə�肭�g����)
	//static int GetInputHorizontal();

	//// �c���͂�-1,0,1��Ԃ��֐�(speed�ƐώZ����Ə�肭�g����)
	//static int GetInputVertital();
};