#include "template.h"


int key[256] = { 0 };

// キー入力用
int gpUpdateKey() {
	char tmpKey[256] = { 0 };
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) 
			key[i]++;
		else 
			key[i] = 0;
	}
	return 0;
}


// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// 初期設定
	ChangeWindowMode(TRUE);
	SetMainWindowText(TITLE);
	SetGraphMode(WIDTH, HEIGHT, 32);

	if (DxLib_Init() < 0) return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 &&
		key[ESC] == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {}


	DxLib_End();

	return 0;

}
