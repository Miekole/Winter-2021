#include <ctime>
#include <iostream>
#include "Person.h"
#include "Survey.h"

using namespace std;

int main()
{
	Survey survey;
	int num = 0,
	srand(time(NULL));
	for(bool done = false; done == false; done = done)
	{
		string choice = "";
		cout << "1. Add People\n";
		cout << "2. View Results\n";
		cout << "3. Exit\n\n\n";
		cout << "Choice: ";
		cin >> choice;
		if (choice == "1")
		{
			cout << "\n\nHow many people?: ";
			cin >> num;
			for(int i = 0; i < num; i++)
			{
				survey.addStudent();
			}
		}
		else if (choice == "2")
		{
			cout << survey.GetAverage() << endl;
		}
		else if (choice == "3")
		{
			done = true;
		}
	}
	return 0;
}