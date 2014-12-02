#pragma once

#include<vector>

using namespace std;

class Bottle
{

	int max;

	int state;

public:

	Bottle();

	Bottle(int max, int state = 0);

	virtual ~Bottle();

	void prelit(Bottle &other);

};

typedef vector<Bottle> BottlesInGame;

