#pragma once

#include <list>

#include "Calculator.h"

class PoolManager
{
public:

	typedef std::list<Calculator *> CalculatorList;

private:

	/* seznam kalkulacek ve fondu */
	CalculatorList calculators;

	// velikost fondu
	int size;

public:
	PoolManager();

	PoolManager(int poolSize);

	~PoolManager();

	Calculator *BorrowCalculator();

	void ReturnCalculator(Calculator *calc);

	int GetSize() const;

};

