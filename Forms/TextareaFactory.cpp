#include "stdafx.h"
#include "TextareaFactory.h"


TextareaFactory::TextareaFactory()
{
}


TextareaFactory::~TextareaFactory()
{
}

FormElement *TextareaFactory::CreateElement(string name, string value)
{
	TextArea *retVal = new TextArea();
	retVal->SetName(name);
	retVal->SetValue(value);

	return retVal;
}
