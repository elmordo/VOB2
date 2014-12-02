#include "stdafx.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}



const string &Input::GetType() const
{
	return type;
}

void Input::SetType(const string &type)
{
	this->type = type;
}

string Input::ToString() const
{
	string retVal;

	retVal = "<input type=\"" + type + "\" value=\"" + GetValue() + "\" name=\"" + GetName() + "\"" + buildAttributes() + "/>";

	return retVal;
}
