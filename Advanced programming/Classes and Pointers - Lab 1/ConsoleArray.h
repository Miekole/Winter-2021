#pragma once
#include <iostream>
#include <string>
using namespace std;


class Console
{
private:
	string g_cName, g_cPublisher;
	int arraySize;
public:
	Console(int size, string name, string publisher);
	Console();
	~Console();
	void print() const;
	void setCName(string n);
	void setCPublisher(string p);
	void setSize(int size);
};