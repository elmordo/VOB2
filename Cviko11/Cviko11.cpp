// Cviko11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <string>

#include "Node.h"
#include "NodeContainer.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int cnt;

	cout << "Kolik bude uzlu?" << endl;
	cin >> cnt;

	NodeContainer nodes;

	for (int i = 0; i < cnt; ++i)
	{
		cout << "Zadejte jmeno uzlu " << (i + 1) << ": ";

		string nodeName;

		cin >> nodeName;
		nodes.CreateNode(nodeName);
	}

	// test - vypsani vsech uzlu
	NodeContainer::NodeList nodeList = nodes.GetNodes();

	for (auto pos = nodeList.begin(); pos != nodeList.end(); ++pos)
	{
		cout << (*pos)->GetName() << endl;
	}

	cin.get();

	return 0;
}

