#pragma once
#include "AbstractOperation.h"
class SwapMilk :
	public AbstractOperation
{

	int fromIndex;

	int toIndex;

public:
	SwapMilk();
	virtual ~SwapMilk();

	virtual void doOperation(BottlesInGame bottles);
};

