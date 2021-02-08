#include "Character.h"
#include <iostream>
using namespace std;

Knight::Knight(string name)
{
	SetName(name);
	SetHealth(20);
	SetRole(KNIGHT);
}

Ghost::Ghost(string name)
{
	SetName(name);
	SetHealth(-20);
	SetRole(GHOST);
}

Skeleton::Skeleton(string name)
{
	SetName(name);
	SetHealth(5);
	SetRole(SKELETON);
}

Rock::Rock(string name)
{
	SetName(name);
	SetHealth(50);
	SetRole(ROCK);
}
