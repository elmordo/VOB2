#include "stdafx.h"
#include "PoolManager.h"


PoolManager::PoolManager()
{
	size = 0;
}

PoolManager::PoolManager(int poolSize)
{
	size = poolSize;

	for (int i = 0; i < size; ++i)
	{
		calculators.push_back(new Calculator());
	}
}

PoolManager::~PoolManager()
{
}

Calculator *PoolManager::BorrowCalculator()
{
	if (calculators.size() == 0)
	{
		return 0x0;
	}

	Calculator *retVal = calculators.front();
	calculators.pop_front();

	return retVal;
}

void PoolManager::ReturnCalculator(Calculator *calc)
{
	if (size == calculators.size())
	{
		throw 1;
	}

	calculators.push_back(calc);
}

int PoolManager::GetSize() const
{
	return calculators.size();
}
