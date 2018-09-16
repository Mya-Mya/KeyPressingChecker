#pragma once
#include<vector>

class Particle {
private:
	int color;
	int x, y;
	char *kind;
	int expspeed, limitr, currentr;
public:
	Particle(char *in);
	int Do();
};

class mParticle {
private:
	int re;
	std::vector<Particle*> list;
	std::vector<Particle*>::iterator ilist;
	std::vector<Particle*>::iterator bilist;
public:
	mParticle();
	void Make(char *in);
	void Do();
};