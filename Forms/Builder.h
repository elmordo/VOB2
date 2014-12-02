#pragma once

#include "InputFactory.h"
#include "TextareaFactory.h"

#include <map>
#include <string>

using namespace std;

class Builder
{
public:

	typedef map<string, AbstractFactory *> FactoryMap;

private:

	FactoryMap factories;

public:

	Builder();

	virtual ~Builder();

	FormElement *BuildElement(string type, string name, string value) const;

};

