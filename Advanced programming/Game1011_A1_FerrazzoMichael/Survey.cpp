#include <iostream>
#include  <string>
#include "Survey.h"
#include <time.h>
#include <stdlib.h>;

using namespace std;


Survey::Survey()
{
}

void Survey::addStudent()
{
	int random = rand() % 2;
	if (random == 0)
	{
		arr[size] = new GamingStudent(static_cast<dName>(rand() % 6 + 1),
			rand() % 100 + 1, rand() % 30 + 19, static_cast<cName>(rand() % 6 + 1), static_cast<pName>(rand() % 6 + 1), static_cast<sName>(rand() % 6 + 1));
	}
	else if (random == 1)
	{
		arr[size] = new NonGamingStudent(static_cast<sName>(rand() % 6 + 1),
			rand() % 100 + 1, rand() % 30 + 19, static_cast<cName>(rand() % 6 + 1), static_cast<pName>(rand() % 6 + 1), static_cast<sName>(rand() % 6 + 1));
	}
	size++;
}

void Survey::SetSize(int size)
{
	this->size = size;
}

int Survey::GetSize()
{
	return size;
}

Person* Survey::GetAverage()
{
	int x = 0;
	for(int i = 0; i < size; i++)
	{
		x += arr[size]->GetAge();
	}
	return arr[size];
}
