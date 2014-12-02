#include "stdafx.h"
#include "FormElement.h"


FormElement::FormElement()
{
}

FormElement::FormElement(const FormElement &other)
{
	operator=(other);
}

FormElement::~FormElement()
{
}

const string &FormElement::GetName() const 
{
	return name;
}

void FormElement::SetName(const string &name)
{
	this->name = name;
}

const string &FormElement::GetValue() const
{
	return value;
}

void FormElement::SetValue(const string &value)
{
	this->value = value;
}

const FormElement::AttrMap &FormElement::GetAttributes() const
{
	return attrs;
}

FormElement::AttrMap &FormElement::GetAttributes()
{
	return attrs;
}

FormElement &FormElement::operator =(const FormElement &other)
{
	attrs = other.attrs;
	name = other.name;
	value = other.value;

	return *this;
}

string FormElement::buildAttributes() const
{
	string retVal = "";

	for (AttrMap::const_iterator pos = attrs.cbegin();
		pos != attrs.cend();
		++pos)
	{
		retVal += " " + pos->first + "=\"" + pos->second + "\"";
	}

	return retVal;
}

