#include "DxLib.h"
#include "Board.h"
#include "Resource.h"
#include "KeyBoardInput.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "�Ǝ팤��_02";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 500;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	SetMouseDispFlag(FALSE);

	int MouseX, MouseY;

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	LoadPic();


	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	KeyboardInput key;

	const int C_White = GetColor(255, 255, 255);

	bool isClick = false;

	// �Q�[�����[�v
	while (true) {

		key.Update();

		// �}�E�X�̈ʒu���擾
		GetMousePoint(&MouseX, &MouseY);


		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	isClick = TRUE;
		else											isClick = FALSE;

		// �`�揈��
		DrawBase();

		DrawCircle(MouseX, MouseY, 12, C_White);

		DrawFormatString(0, 0, C_White, "MouseX : %d", MouseX);
		DrawFormatString(0, 20, C_White, "MouseY : %d", MouseY);
		DrawFormatString(0, 60, C_White, "isClick : %d", isClick);

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	DeletePic();
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
