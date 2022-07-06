#include "DxLib.h"
#include "Board.h"
#include "Resource.h"
#include "KeyBoardInput.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "業種研究_02";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 500;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	SetMouseDispFlag(FALSE);

	int MouseX, MouseY;

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み
	LoadPic();


	// ゲームループで使う変数の宣言

	KeyboardInput key;

	const int C_White = GetColor(255, 255, 255);

	bool isClick = false;

	// ゲームループ
	while (true) {

		key.Update();

		// マウスの位置を取得
		GetMousePoint(&MouseX, &MouseY);


		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	isClick = TRUE;
		else											isClick = FALSE;

		// 描画処理
		DrawBase();

		DrawCircle(MouseX, MouseY, 12, C_White);

		DrawFormatString(0, 0, C_White, "MouseX : %d", MouseX);
		DrawFormatString(0, 20, C_White, "MouseY : %d", MouseY);
		DrawFormatString(0, 60, C_White, "isClick : %d", isClick);

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	DeletePic();
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
