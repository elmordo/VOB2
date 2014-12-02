#include "stdafx.h"
#include "CoutAdapter.h"


CoutAdapter::CoutAdapter()
{
}


CoutAdapter::~CoutAdapter()
{
}

void CoutAdapter::SendMessage(const string &msg)
{
	cout << formatMessage(msg) << endl;
}