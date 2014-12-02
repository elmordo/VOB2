#pragma once

#include<vector>

#include "Bottle.h"

using namespace std;

class AbstractOperation
{
public:
	AbstractOperation();

	virtual ~AbstractOperation();

	virtual void doOperation(BottlesInGame bottles) = 0;
};

