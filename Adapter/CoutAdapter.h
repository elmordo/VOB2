#pragma once
#include "AdapterAbstract.h"

#include <iostream>

using namespace std;

class CoutAdapter :
	public AdapterAbstract
{
public:
	CoutAdapter();
	virtual ~CoutAdapter();

	virtual void SendMessage(const string &msg);
};

