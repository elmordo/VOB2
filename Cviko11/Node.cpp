#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
	Disconnect();
}

void Node::AddConnection(Node *otherNode, double val)
{
	// odstraneni pripadne duplicity
	RemoveConnection(otherNode);

	// vytvoreni hrany
	Edge e;
	e.first = this;
	e.second = otherNode;
	e.val = val;

	connections.push_back(e);
	otherNode->connections.push_back(e);
}

void Node::Disconnect()
{
	// dokud je nejake spojeni k dispozici, odebirame spojeni
	while (connections.size())
	{
		// nacteni posledni hrany
		Edge edge = connections.front();
		Node *toRemove = edge.first == this ? edge.second : edge.first;

		// odstraneni spojeni z druheho uzlu
		toRemove->connections.remove(edge);

		// odstraneni posledni hrany ze seznamu
		connections.pop_front();
	}
}

void Node::RemoveConnection(Node *otherNode) 
{
	// najdeme spojeni
	for (EdgeList::iterator pos = connections.begin(); pos != connections.end(); ++pos)
	{
		auto edge = *pos;
		auto otherSide = edge.first == this ? edge.second : edge.first;

		if (otherNode == otherSide)
		{
			// nalezli jsme spravne spojeni
			connections.remove(edge);
			otherSide->connections.remove(edge);
			return;
		}
	}
}

string Node::GetName() const
{
	return nodeName;
}

void Node::SetName(const string &name)
{
	nodeName = name;
}