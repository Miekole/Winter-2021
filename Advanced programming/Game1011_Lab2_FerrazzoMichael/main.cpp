#include <iostream>
#include <vector>
#include "Character.h"
using namespace std;

const string rName[] = { "Knight", "Ghost", "Skeleton", "Rock" };
const string wName[] = { "Sword", "Mace", "Spear" };
bool play = false;

int main()
{
	Character* arr[100];
	int NUM_CHARACTERS = 0;
	int size = 0;
	string choice;
	bool done = false;
	while (done != true)
	{
		cout << "\nMake a new character?\n";
		cout << "1.New Characters\n";
		cout << "2.View All\n";
		cout << "3.Exit\n\n";
		cout << "Choice:";
		cin >> choice;
		if (choice == "1")
		{
			cout << "How Many?: ";
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				string name = "";
				cout << "\n\n";
				cout << "1.Knight\n";
				cout << "2.Ghost\n";
				cout << "3.Skeleton\n";
				cout << "4.Rock\n";
				cout << "\n\n";
				cout << "What is your characters class: ";
				cin >> choice;
				cout << "What is your characters name: ";
				cin >> name;
				if (choice == "1")
				{
					arr[NUM_CHARACTERS] = new Knight(name);
				}
				else if (choice == "2")
				{
					arr[NUM_CHARACTERS] = new Ghost(name);
				}
				else if (choice == "3")
				{
					arr[NUM_CHARACTERS] = new Skeleton(name);
				}
				else if (choice == "4")
				{
					arr[NUM_CHARACTERS] = new Rock(name);
				}
				choice = "0";
				NUM_CHARACTERS++;
			}
		}

		else if (choice == "2")
		{
			for (int i = 0; i < NUM_CHARACTERS; i++)
			{
				cout << arr[i]->GetName() << endl << endl;
			}
		}

		else if (choice == "3")
		{
			done = true;
		}
	}
	return 0;
}