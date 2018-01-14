#include "Physics.h"
#include <SFML\Graphics.hpp>
#include "MapMgr.h"
#include "GameState.h"
bool testLeft(float x, float y)
{
	bool noObject = true;
	int modY = (int)y / 32;
	sf::Vector2i current = getMap(x-1, y + modY);
	if (current.x != -1)
		noObject = false;

	return noObject;
}

bool testRight(float x, float y)
{
	bool noObject = true;
	int modY = (int)y % 32;
	sf::Vector2i current = getMap(x + 32, y + modY);
	if (current.x != -1)
		noObject = false;

	return noObject;
}

bool testUp(float x, float y)
{
	bool noObject = true;
	int modX = (int)x % 32;
	sf::Vector2i current = getMap(x + modX, y - 1);
	if (current.y != -1)
		noObject = false;

	return noObject;
}

bool testDown(float x, float y)
{
	bool noObject = true;
	int modX = (int)x % 32;
	sf::Vector2i current = getMap(x + modX, y + 32);
	if (current.y != -1)
	{
		noObject = false;
	}


	return noObject;
}

