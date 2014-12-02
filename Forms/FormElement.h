#pragma once

#include <string>
#include <map>

using namespace std;

class FormElement
{
public:

	typedef map<string, string> AttrMap;

private:

	string name;

	string value;

	AttrMap attrs;

protected:

	string buildAttributes() const;

public:

	FormElement();

	FormElement(const FormElement &other);

	virtual ~FormElement();

	const string &GetName() const;

	void SetName(const string &name);

	const string &GetValue() const;

	void SetValue(const string &value);

	const AttrMap &GetAttributes() const;

	AttrMap &GetAttributes();

	virtual string ToString() const = 0;

	FormElement &operator =(const FormElement &other);

};

