// Decorator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Mnamka {

public:

	virtual int Cena() const = 0;

	virtual string Chut() const = 0;

};

class Zmrzlina : public Mnamka {

	string prichut;

public:

	Zmrzlina() {
		prichut = "jahodova";
	}

	virtual ~Zmrzlina() {}

	void SetPrichut(string newOne) {
		prichut = newOne;
	}

	virtual int Cena() const {
		return 3;
	}

	virtual string Chut() const {
		return prichut + " zmrzlina";
	}
};

class AbstractDecorator : public Mnamka {

protected:

	Mnamka *parent;

public:

	AbstractDecorator(Mnamka *parent) {
		this->parent = parent;
	}

	virtual ~AbstractDecorator() {}

	Mnamka **GetRoot() {
		AbstractDecorator *p = dynamic_cast<AbstractDecorator *>(parent);

		if (p == 0x0) 
		{
			return &parent;
		}
		else 
		{
			return p->GetRoot();
		}
	}
};

class Orisky : public AbstractDecorator {

public:

	Orisky(Mnamka *parent) : AbstractDecorator(parent) {}

	virtual ~Orisky() {}

	virtual int Cena() const {
		return parent->Cena() + 1;
	}

	virtual string Chut() const {
		return parent->Chut() + " s orisky";
	}
};

class Poleva : public AbstractDecorator {

public:

	Poleva(Mnamka *parent) : AbstractDecorator(parent) {}

	virtual ~Poleva() {}

	virtual int Cena() const {
		return parent->Cena() + 1;
	}

	virtual string Chut() const {
		return parent->Chut() + " s cokoladovou polevou";
	}
};

class Kornout : public AbstractDecorator {

public:

	Kornout(Mnamka *parent) : AbstractDecorator(parent) {}

	virtual ~Kornout() {}

	virtual int Cena() const {
		return parent->Cena() + 1;
	}

	virtual string Chut() const {
		return parent->Chut() + " ve sladkem kornoutu";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	Zmrzlina zm, cintronova;
	cintronova.SetPrichut("citronova");

	Orisky o(&zm);
	Poleva p(&o);
	Kornout k(&p);

	cout << "Cena: " << k.Cena() << endl;
	cout << "Chut: " << k.Chut() << endl;

	cout << "-------------------" << endl;

	*k.GetRoot() = &cintronova;

	cout << "Cena: " << k.Cena() << endl;
	cout << "Chut: " << k.Chut() << endl;

	cin.get();

	return 0;
}

