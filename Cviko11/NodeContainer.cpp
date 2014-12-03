#include "stdafx.h"
#include "NodeContainer.h"


NodeContainer::NodeContainer()
{
}


NodeContainer::~NodeContainer()
{
	// dealokace vsech uzlu
	Node::NodeAllocator allocator;

	for (auto pos = nodes.begin(); pos != nodes.end(); ++pos)
	{
		allocator.deallocate(*pos, 1);
	}
}

Node *NodeContainer::CreateNode(const string &name)
{
	// alokace a vytvoreni uzlu
	Node::NodeAllocator allocator;
	Node *retVal = allocator.allocate(1);
	allocator.construct(retVal);

	// nastaveni jmena a pridani uzlu do seznamu
	retVal->SetName(name);
	nodes.push_back(retVal);

	return retVal;
}

Node *NodeContainer::FindByName(const string &name)
{
	Node *retVal = 0x0;
	auto pos = nodes.begin();

	while (retVal == 0x0 && pos != nodes.end())
	{
		if ((*pos)->GetName() == name)
			retVal = *pos;

		++pos;
	}

	return retVal;
}
