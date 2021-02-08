#pragma once
#include <string>
#include "Character.h"
using namespace std;

enum wName {SWORD, MACE, SPEAR };

class Weapon
{
private:
	wName wep;
	int dmg;
public:
	Weapon()
	{
		SetWeapon(SWORD);
		SetDamage(0);
		
	}
	Weapon(wName name, int dmg)
	{
		SetWeapon(name);
		SetDamage(dmg);
	}
	virtual void DisplaySpecialAbility() const = 0;
	void SetWeapon(wName w)
	{
		wep = w;
	}
	wName GetWeapon() const
	{
		return wep;
	}
	void SetDamage(int d)
	{
		dmg = d;
	}
	int GetDamage() const
	{
		return dmg;
	}
	/*void SetSpecialAbility(string a)
	{
		spAbility = a;
	}
	string GetSpecialAbility() const
	{
		return spAbility;
	}*/
};

class Sword : public  Weapon
{
public:
	Sword();
};

class Spear : Weapon
{
public:
	Spear();
};

class Mace : Weapon
{
public:
	Mace();
};
