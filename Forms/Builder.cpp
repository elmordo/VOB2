#include "stdafx.h"
#include "Builder.h"


Builder::Builder()
{
	factories["textarea"] = new TextareaFactory();
	factories["input"] = new InputFactory();
}


Builder::~Builder()
{
	delete factories["textarea"];
	delete factories["input"];
}

FormElement *Builder::BuildElement(string type, string name, string value) const
{
	if (factories.find(type) == factories.cend()) return 0x0;

	return factories.find(type)->second->CreateElement(name, value);
}
