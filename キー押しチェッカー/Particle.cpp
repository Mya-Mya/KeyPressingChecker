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
	if (currentr > limitr) return 1;//削除要請

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
		if ((*ilist)->Do() == 1) {//削除要請が来たら
			//当該イテレータの要素を削除し、次のイテレータに定める
			//例外発生します:eraseで当該イテレータの要素を削除すると、++によりイテレータはチェックインできない
			ilist = (list.erase(ilist));
		} else {
			//次のイテレータに定める
			++ilist;
		}
	}
}

