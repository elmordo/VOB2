// Prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

template<typename BASE_CLASS>
class Cloneable {

public:

	virtual BASE_CLASS *clone() const = 0;

};

class ADiv : public Cloneable<ADiv> {

	int index;

public:

	string content;

	string htmlClass;

	ADiv() {
		index = 0;
	}

	ADiv(const ADiv &other) {
		content = other.content;
		htmlClass = other.htmlClass;
	}

	virtual ADiv *clone() const {
		ADiv *retVal = new ADiv(*this);
		retVal->index += 1;

		return retVal;
	}

};

class BDiv : public ADiv {

public:

	string title;

	BDiv() {

	}

	BDiv(string title) {
		this->title = title;
	}

	BDiv(const BDiv &other) : ADiv(other) {
		title = other.title;
	}

	virtual ADiv *clone() const {
		return new BDiv(*this);
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	// zatim jde pouzit kopirovaci konstruktor
	ADiv proto;
	proto.htmlClass = "figures";

	ADiv klon(proto);
	klon.content = "a + b";

	cout << klon.htmlClass << endl;
	cout << klon.content << endl;

	// ted uz nemuzeme pouzit kopirovaci konstruktor, protoze nevime, jake tridy je instance v proto2
	ADiv *proto2 = new BDiv(/*"nejakz titulek"*/);
	proto2->htmlClass = "trida prototypu 2";

	
	BDiv *klon2 = dynamic_cast<BDiv *>(proto2->clone());

	if (klon2 == 0x0) {
		cout << "Klonovani se nepovedlo. Objekt neni instance tridy BDiv" << endl;
		cin.get();
		return 1;
	}

	cout << klon2->htmlClass << endl;
	cout << klon2->content << endl;
	cout << klon2->title << endl;

	cin.get();

	return 0;
}

