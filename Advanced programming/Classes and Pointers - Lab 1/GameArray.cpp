#include <iostream>
#include <string>
#include "GameArray.h"

Game::Game(int size, std::string name, std::string publisher)
{
	g_gName = name;
	g_gPublisher = publisher;
}

Game::Game()
{
	g_gName = "None";
	g_gPublisher = "None";
}

Game::~Game()
{
}

//	Print all the entries of the array
void Game::print() const
{
		std::cout << g_gName << std::endl;
		std::cout << g_gPublisher << std::endl;
}

void Game::setGameName(std::string n)
{
		g_gName = n;
}

void Game::setPublisher(string p)
{
		g_gPublisher = p;
}

void Game::setSize(int size)
{
	arraySize = size;
}

