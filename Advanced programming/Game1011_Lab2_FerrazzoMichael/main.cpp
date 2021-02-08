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
	for(bool p = false; p != true; p = false) 
	{
		int size = 0;
		string choice;
		cout << "Make a new character?\n";
		cout << "1.New Characters\n";
		cout << "2.View All\n";
		cout << "3.Exit\n\n";
		cout << "Choice:";
		getline(cin, choice);
		bool done = false;
		while (done != true)
		{
			cout << "How Many?: ";
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				if (choice == "1")
				{
					string name = "";
					cout << "\n\n";
					cout << "1.Knight\n";
					cout << "2.Ghost\n";
					cout << "3.Skeleton\n";
					cout << "4.Rock\n";
					cout << "\n\n";
					getline(cin, choice);
					cout << "What is your characters name: ";
					getline(cin, name);
					if (choice == "1")
					{
						arr[NUM_CHARACTERS] = new Knight(name);
					}
					else if (choice == "2")
					{
						arr[NUM_CHARACTERS] =  new Ghost(name);
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
				else if (choice == "2")
				{

				}
				else if (choice == "3")
				{
					p = true;
				}
			}
		}
	}
	return 0;
}