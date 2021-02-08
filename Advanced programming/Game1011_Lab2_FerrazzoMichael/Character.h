#pragma once
#include "Weapon.h"
#include <iostream>
#include <string>

using namespace std;

enum Role { KNIGHT, GHOST, SKELETON, ROCK};

class Character
{
private:
	Role choice;
	string name;
	int health;
public:
	Character()
	{
		SetName("");
		SetHealth(0);
		SetRole(KNIGHT);
	}
	Character(Role choice, string name, int health)
	{
		SetRole(choice);
		SetName(name);
		SetHealth(health);
	}
	virtual void DisplayInfo() const = 0;	// Pure virtual function
	void SetRole(Role r)
	{
		choice = r;
	}
	Role GetRole() const
	{
		return choice;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName() const
	{
		return name;
	}
	void SetHealth(int health)
	{
		this->health = health;
	}
	int GetHealth() const
	{
		return health;
	}
};

class Knight : public Character
{
private:
	Role choice;
public:
	Knight(string name);

	// Overide the getName 
	virtual string GetName() const
	{
		return "Sir. " + Character::GetName();
	}
	virtual void DisplayInfo() const
	{
		cout << "'The Dark Knight' is a  good movie that reached both critics and mainstream audiences.";
	}
};

class Ghost : public Character
{
private:
	Role choice;
public:
	Ghost(string name);

	// Overide the getName 
	virtual string GetName() const
	{
		return "oOoOo " + Character::GetName() + " oOoOo";
	}
	virtual void DisplayInfo() const
	{
		cout << "BOO! scary :(";
	}
};

class Skeleton : public Character
{
public:
	Skeleton(string name);
	
	// Overide the getName 
	virtual string GetName() const
	{
		return "Pile of bones " + Character::GetName();
	}
	virtual void DisplayInfo() const
	{
		cout << "*xylophone noises*";
	}
};

class Rock : public  Character
{
public:
	Rock(string name);
	
	// Overide the getName 
	virtual string GetName() const
	{
		return Character::GetName() + ", the rock, Jonson";
	}
	virtual void DisplayInfo() const
	{
		cout << "''Success isn't always about 'greatness', it's about consistency. Consistent, hard work gains success.'' -Dwayne Johnson";
	}
};