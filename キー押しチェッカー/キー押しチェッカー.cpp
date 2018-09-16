/* ～パーティクルインスタンス～
一定条件によって現れ、一定条件によって消滅する、同時に複数存在する可能性のあるインスタンス(以下粒と呼ぶ)の管理方法として、
所有者はリスト構造コンテナによって粒を管理し、役目を終了すると粒から所有者に戻り値で知らせて、所有者が然るべき対処をする方法を提案する。
*/

#include "stdafx.h"
#include"DxLib.h"
#include"Particle.h"
#include"Keyboard.h"

#define WIDTH 1280
#define HEIGHT 720


int main()
{
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	
	mParticle *pmParticle = new mParticle();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		Keyboard::Instance()->Update();
		{
			if (Keyboard::Instance()->Get(KEY_INPUT_Q) == 1) pmParticle->Make("Q");
			if (Keyboard::Instance()->Get(KEY_INPUT_W) == 1) pmParticle->Make("W");
			if (Keyboard::Instance()->Get(KEY_INPUT_E) == 1) pmParticle->Make("E");
			if (Keyboard::Instance()->Get(KEY_INPUT_R) == 1) pmParticle->Make("R");
			if (Keyboard::Instance()->Get(KEY_INPUT_T) == 1) pmParticle->Make("T");
			if (Keyboard::Instance()->Get(KEY_INPUT_Y) == 1) pmParticle->Make("Y");
			if (Keyboard::Instance()->Get(KEY_INPUT_U) == 1) pmParticle->Make("U");
			if (Keyboard::Instance()->Get(KEY_INPUT_I) == 1) pmParticle->Make("I");
			if (Keyboard::Instance()->Get(KEY_INPUT_O) == 1) pmParticle->Make("O");
			if (Keyboard::Instance()->Get(KEY_INPUT_P) == 1) pmParticle->Make("P");
			if (Keyboard::Instance()->Get(KEY_INPUT_A) == 1) pmParticle->Make("A");
			if (Keyboard::Instance()->Get(KEY_INPUT_S) == 1) pmParticle->Make("S");
			if (Keyboard::Instance()->Get(KEY_INPUT_D) == 1) pmParticle->Make("D");
			if (Keyboard::Instance()->Get(KEY_INPUT_F) == 1) pmParticle->Make("F");
			if (Keyboard::Instance()->Get(KEY_INPUT_G) == 1) pmParticle->Make("G");
			if (Keyboard::Instance()->Get(KEY_INPUT_H) == 1) pmParticle->Make("H");
			if (Keyboard::Instance()->Get(KEY_INPUT_J) == 1) pmParticle->Make("J");
			if (Keyboard::Instance()->Get(KEY_INPUT_K) == 1) pmParticle->Make("K");
			if (Keyboard::Instance()->Get(KEY_INPUT_L) == 1) pmParticle->Make("L");
			if (Keyboard::Instance()->Get(KEY_INPUT_Z) == 1) pmParticle->Make("Z");
			if (Keyboard::Instance()->Get(KEY_INPUT_X) == 1) pmParticle->Make("X");
			if (Keyboard::Instance()->Get(KEY_INPUT_C) == 1) pmParticle->Make("C");
			if (Keyboard::Instance()->Get(KEY_INPUT_V) == 1) pmParticle->Make("V");
			if (Keyboard::Instance()->Get(KEY_INPUT_B) == 1) pmParticle->Make("B");
			if (Keyboard::Instance()->Get(KEY_INPUT_N) == 1) pmParticle->Make("N");
			if (Keyboard::Instance()->Get(KEY_INPUT_M) == 1) pmParticle->Make("M");
		}
		pmParticle->Do();
	}

	DxLib_End();
	return 0;
}

