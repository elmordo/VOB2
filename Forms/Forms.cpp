// Forms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Input.h"
#include "TextArea.h"
#include "TextareaFactory.h"
#include "InputFactory.h"
#include "Builder.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Builder builder;

	TextArea *txt = (TextArea *) builder.BuildElement("textarea", "area1", "bla bla bla");
	
	Input *inp = (Input *)builder.BuildElement("input", "input1", "nejaka jina hodnota");
	inp->SetType("hidden");

	txt->GetAttributes()["styles"] = "background-color: red; ";

	cout << txt->ToString() << endl;
	cout << inp->ToString() << endl;

	delete txt;
	delete inp;

	cin.get();
	return 0;
}

