#include <iostream>
#include <string>
#include "GameArray.h"
#include "ConsoleArray.h"
#include "AcheivmentArray.h"
using namespace std;

int main()
{
	int num = 0;
	cout << "how many acheivments?: ";
	cin >> num;
	Game* game = new Game[num];
	Console* console = new Console[num];
	Acheivment* acheivment = new Acheivment[num];


	for (int i = 0; i < num; i++)
	{
		int aPoints;
		string
			gName,
			gPublisher,
			cName,
			cPublisher,
			aName,
			aRequirement;

		// Console 
		cout << endl;
		cout << "Enter console name: ";
		cin.get();
		getline(cin,cName);
		cout << endl;
		cout << "Enter console's publisher: ";
		getline(cin, cPublisher);
		cout << endl;

		// Game
		cout << "Enter game name: ";
		getline(cin, gName);
		cout << endl;
		cout << "Enter games publisher: ";
		getline(cin, gPublisher);
		cout << endl;

		// Acheivment
		cout << "Enter acheivment name: ";
		getline(cin, aName);
		cout << endl;
		cout << "Enter acheivment requirments: ";
		getline(cin, aRequirement);
		cout << endl;
		cout << "Enter acheivment points: ";
		cin >> aPoints;
		cout << endl;

		game[i].setGameName(gName);
		game[i].setPublisher(gPublisher);
		console[i].setCName(cName);
		console[i].setCPublisher(cPublisher);
		acheivment[i].setAName(aName);
		acheivment[i].setARequirement(aRequirement);
		acheivment[i].setAPoints(aPoints);

	}

	for (int i = 0; i < num; i++)
	{
		cout << endl;
		console[i].print();
		game[i].print();
		acheivment[i].print();
		
	}
	cin.get();
	return 0;
}