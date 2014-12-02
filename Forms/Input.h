#pragma once
#include "FormElement.h"

using namespace std;

class Input :
	public FormElement
{

	string type;

public:
	Input();

	Input(const Input &other) : FormElement(other)
	{
		type = other.type;
	}

	virtual ~Input();

	const string &GetType() const;

	void SetType(const string &type);

	virtual string ToString() const;

	Input &operator =(const Input &other) {
		FormElement::operator=(other);
		return *this;
	}

};

