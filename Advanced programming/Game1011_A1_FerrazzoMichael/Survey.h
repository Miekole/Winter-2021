#pragma once
#include <iostream>
#include  <string>
#include "Person.h"

using namespace std;

class Survey
{
private:
	Person* arr[500];
	int size = 0;
public:
	Survey();
	void addStudent();
	void SetSize(int size);
	int GetSize();
	Person* GetAverage();
};