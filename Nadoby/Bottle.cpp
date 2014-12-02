#include "stdafx.h"
#include "Bottle.h"


Bottle::Bottle()
{
}


Bottle::~Bottle()
{
}

void Bottle::prelit(Bottle &other) {
	// maximum co se vejde
	int maxIn = max - state;

	if (maxIn < other.state) {
		state += maxIn;
		other.state -= maxIn;
	}
	else 
	{
		state += other.state;
		other.state = 0;
	}
}
