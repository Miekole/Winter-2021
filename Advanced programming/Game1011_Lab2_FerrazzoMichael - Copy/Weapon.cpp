#include "Weapon.h"
#include <iostream>

using namespace std;

Sword::Sword()
{
	SetWeapon(SWORD);
	SetDamage(4);
}

Spear::Spear()
{
	SetWeapon(SPEAR);
	SetDamage(3);
}

Mace::Mace()
{
	SetWeapon(SPEAR);
	SetDamage(5);
}