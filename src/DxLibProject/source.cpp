#include "template.h"


int key[256] = { 0 };

// ƒL[“ü—Í—p
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


// WinMainŠÖ”
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// ‰Šúİ’è
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
