// Pool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "PoolManager.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	/*
	program se zepta uzivatele, jak velky fond se ma vytvorit
	potom vytvori ten fond
	a nasledne uzivatel zadava prikazy B, R a E
	B - pujcit
	R - vratit
	E - konec
	pokud uzivatel pujci pres moc, se vypise varovani
	*/
	int fSize;

	cout << "Jak velky fond mam vytvorit?: ";
	cin >> fSize;

	PoolManager pool(fSize);
	char cmd = 'E';

	// pocet pujcenych kalkulacek a pomocny seznam kam se kalkulacky davaji na hromadu
	int borNum = 0;
	Calculator **calcs = new Calculator *[fSize];

	do {
		cout << "Co mam udelat? B, R, E: ";
		cin >> cmd;

		switch (cmd)
		{
		case 'B':
			// pojceni kalkulacky
			calcs[borNum] = pool.BorrowCalculator();

			// pokud je na pozici 0x0, pak zadna kalkulacka ve fondu nezbyla
			if (calcs[borNum] == 0x0)
			{
				cout << "Zadna kalkulacka ve fondu neni" << endl;
			}
			else
			{
				cout << "Kalkulacka pujcena" << endl;
				++borNum;
			}
			break;

		case 'R':
			if (borNum)
			{
				pool.ReturnCalculator(calcs[--borNum]);
				cout << "Kalkulacka vracena" << endl;
			}
			else 
			{
				cout << "Vse je vraceno, neni co vracet" << endl;
			}
			break;

		case 'E':
			break;
		}
	} while (cmd != 'E');

	delete[] calcs;

	return 0;
}

