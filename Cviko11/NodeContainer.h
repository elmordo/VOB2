#pragma once

#include <list>

#include "Node.h"

class NodeContainer
{

public:

	typedef list<Node *> NodeList;

private:

	NodeList nodes;

public:
	
	NodeContainer();

	virtual ~NodeContainer();

	/**
	 * vytvori pojmenovany uzel a prida ho do seznamu
	 */
	Node *CreateNode(const string &name);

	inline NodeList GetNodes()
	{
		return nodes;
	}

	/**
	 * najede uzel dle jmena
	 * pokud uzel neexistuje, vraci 0x0
	 */
	Node *FindByName(const string &name);

};

