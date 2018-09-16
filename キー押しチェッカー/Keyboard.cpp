#include "Keyboard.h"
#include"DxLib.h"

void Keyboard::Update()
{
	char tmpKey[256];             // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey);  // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			m_Key[i]++;   // ���Z
		}
		else {              // ������Ă��Ȃ����
			m_Key[i] = 0; // 0�ɂ���
		}
	}
}

int Keyboard::Get(int KeyCode)
{
	return m_Key[KeyCode]; // KeyCode�̓��͏�Ԃ�Ԃ�
}
