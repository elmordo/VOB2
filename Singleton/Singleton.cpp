// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class MySingleton {

	int number;

	static MySingleton *instance;

	MySingleton() {
		number = 1;
	}

public:

	static MySingleton *getInstance() {
		if (instance == 0x0) instance = new MySingleton();

		return instance;
	}

	static void deinit() {
		if (instance != 0x0) delete instance;
	}

};

MySingleton *MySingleton::instance = 0x0;

int _tmain(int argc, _TCHAR* argv[])
{

	MySingleton *sing1 = MySingleton::getInstance();
	MySingleton *sing2 = MySingleton::getInstance();

	if (sing1 == sing2) {
		cout << "je to jedna a ta sama isntance" << endl;
	} else {
		cout << "chyba, nejedna se o stejnou instanci" << endl;
	}

	cin.get();

	MySingleton::deinit();

	return 0;
}

