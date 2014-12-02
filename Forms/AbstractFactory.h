#pragma once

#include <string>

#include "FormElement.h"

using namespace std;

class AbstractFactory
{
public:

	AbstractFactory();
	virtual ~AbstractFactory();

	virtual FormElement *CreateElement(string name, string value) = 0;

};

