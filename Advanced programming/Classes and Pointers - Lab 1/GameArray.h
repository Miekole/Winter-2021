#pragma once
#include <iostream>
#include <string>
using namespace std;

class Game
{
private:
	string g_gName, g_gPublisher;
	int arraySize;
public:
	Game(int size, string name, string publisher);
	Game();
	~Game();
	void print() const;
	void setGameName(string n);
	void setPublisher(string p);
	void setSize(int size);

};
