#include <iostream>
#include <string>
#include "ConsoleArray.h"

Console::Console(int size, string name, string publisher)
{
	g_cName = name;
	g_cPublisher = publisher;
}

Console::Console()
{
	g_cName = "None";
	g_cPublisher = "None";
}

Console::~Console()
{
}

void Console::print() const
{
	std::cout << g_cName << std::endl;
	std::cout << g_cPublisher << std::endl;
}

void Console::setCName(string n)
{
	g_cName = n;
}

void Console::setCPublisher(string p)
{
	g_cPublisher = p;
}

void Console::setSize(int size)
{
	arraySize = size;
}
