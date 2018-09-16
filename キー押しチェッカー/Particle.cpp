#include "Particle.h"
#include"DxLib.h"

Particle::Particle(char * in)
{
	color = GetColor(100 + rand() % 155, 100 + rand() % 155, 100 + rand() % 155);
	x = rand() % 1280;
	y = rand() % 720;
	expspeed = 4 + rand() % 5;
	limitr = 100 + rand() % 250;
	currentr = 0;
	kind = in;
}

int Particle::Do()
{
	currentr += expspeed;
	if (currentr > limitr) return 1;//�폜�v��

	SetDrawBlendMode(DX_BLENDMODE_ADD, 255-(255 *currentr/limitr));
	DrawCircle(x, y, currentr, color, TRUE);
	DrawFormatString(x, y, GetColor(255, 255, 255), kind);
	return 0;
}

mParticle::mParticle()
{
	ilist = list.begin();
	bilist = list.begin();
}

void mParticle::Make(char * in)
{
	list.push_back(new Particle(in));
}

void mParticle::Do()
{
	ilist = list.begin();
	bilist = list.begin();

	while (ilist != list.end()) {
		if ((*ilist)->Do() == 1) {//�폜�v����������
			//���Y�C�e���[�^�̗v�f���폜���A���̃C�e���[�^�ɒ�߂�
			//��O�������܂�:erase�œ��Y�C�e���[�^�̗v�f���폜����ƁA++�ɂ��C�e���[�^�̓`�F�b�N�C���ł��Ȃ�
			ilist = (list.erase(ilist));
		} else {
			//���̃C�e���[�^�ɒ�߂�
			++ilist;
		}
	}
}

