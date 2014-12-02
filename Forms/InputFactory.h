#pragma once
#include "AbstractFactory.h"
#include "Input.h"

class InputFactory :
	public AbstractFactory
{
public:
	InputFactory();

	virtual ~InputFactory();

	virtual FormElement *CreateElement(string name, string value);

};

