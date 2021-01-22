#include "AcheivmentArray.h"

Acheivment::Acheivment(int size, string name, string publisher, int points)
{
	g_aName = name;
	g_aRequirement = publisher;
	g_points = points;
}

Acheivment::Acheivment()
{
	g_aName = "None";
	g_aRequirement = "None";
	g_points = 0;
}

Acheivment::~Acheivment()
{
}

void Acheivment::print() const
{
	std::cout << g_aName << std::endl;
	std::cout << g_aRequirement << std::endl;
	std::cout << g_points << std::endl;
}

void Acheivment::setAName(string n)
{
	g_aName = n;
}

void Acheivment::setARequirement(string r)
{
	g_aRequirement = r;
}

void Acheivment::setAPoints(int p)
{
	g_points = p;
}
