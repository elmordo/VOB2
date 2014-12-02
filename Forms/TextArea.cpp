#include "stdafx.h"
#include "TextArea.h"


TextArea::TextArea()
{
}


TextArea::~TextArea()
{
}

string TextArea::ToString() const 
{
	return "<textarea name=\"" + GetName() + "\"" + buildAttributes() + ">" + GetValue() + "</textarea>";
}
