#pragma once
#include "MapMgr.h"
#include <SFML\Graphics.hpp>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>


sf::Texture tileTexture;
sf::Vector2i map[10][14];
sf::Vector2i loadCounter = sf::Vector2i(0, 0);
sf::Sprite tiles;
float finishX, finishY;

void loadMap(const char *filename)
{
	std::ifstream openFile(filename);

	if (openFile.is_open())
	{
		std::string tileLocation;
		openFile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);

		while (!openFile.eof())
		{
			std::string str;
			openFile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			else
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');
				if (map[loadCounter.x][loadCounter.y].x == 1)
				{
					finishX = loadCounter.x * 32;
					finishY = loadCounter.y * 32;
				}
					
			}

			if (openFile.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
				loadCounter.x++;
		}
		loadCounter.y++;
	}
}


void drawMap(sf::RenderWindow &window)
{
	for (int i = 0; i < loadCounter.x; i++)
		for (int k = 0; k < loadCounter.y; k++)
			if (map[i][k].x != -1 && map[i][k].y != -1)
			{
				tiles.setTexture(tileTexture);
				tiles.setPosition(i * 32, k * 32);
				tiles.setScale(32.f, 32.f);
				tiles.setTextureRect(sf::IntRect(map[i][k].x * 32 + 1, map[i][k].y * 32, 1, 1));
				window.draw(tiles);
			}
				
}

void resetCounter()
{
	loadCounter = sf::Vector2i(0, 0);
}

sf::Vector2i getMap(float x, float y)
{
	return map[(int)x / 32][(int)y / 32];
}

float getFinishX()
{
	return finishX;
}

float getFinishY()
{
	return finishY;
}