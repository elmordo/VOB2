#include "stdafx.h"
#include "InputFactory.h"


InputFactory::InputFactory()
{
}


InputFactory::~InputFactory()
{
}

FormElement *InputFactory::CreateElement(string name, string value)
{
	Input *retVal = new Input();
	retVal->SetName(name);
	retVal->SetValue(value);

	return retVal;
}

