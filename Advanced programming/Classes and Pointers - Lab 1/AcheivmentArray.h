#pragma once
#include <iostream>
#include <string>
using namespace std;


class Acheivment
{
private:
	string g_aName, g_aRequirement;
	int arraySize, g_points;
public:
	Acheivment(int size, string name, string publisher, int points);
	Acheivment();
	~Acheivment();
	void print() const;
	void setAName(string n);
	void setARequirement(string r);
	void setAPoints(int p);
};