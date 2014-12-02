#pragma once
#include "FormElement.h"
class TextArea :
	public FormElement
{
public:
	TextArea();

	TextArea(const TextArea &other) : FormElement(other)
	{
	}

	virtual ~TextArea();

	virtual string ToString() const;

	TextArea &operator =(const TextArea &other)
	{
		FormElement::operator=(other);

		return *this;
	}
};

