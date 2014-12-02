#pragma once

#include "AbstractFactory.h"
#include "TextArea.h"

class TextareaFactory :
	public AbstractFactory
{
public:
	TextareaFactory();
	virtual ~TextareaFactory();

	virtual FormElement *CreateElement(string name, string value);

};

