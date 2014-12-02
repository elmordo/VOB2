// Adapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CoutAdapter.h"
#include "FileAdapter.h"


int _tmain(int argc, _TCHAR* argv[])
{

	FileAdapter adapter;

	CoutAdapter::ConfigMap config;

	config["author"] = "Petr Jindra";
	config["fileName"] = "muj_chat.txt";

	adapter.Configure(config);

	while (1)
	{
		string msg;
		cout << "Zadej zpravu: ";
		cin >> msg;

		adapter.SendMessage(msg);
	}

	return 0;
}

