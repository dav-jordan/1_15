#pragma once
#include <SFML/Graphics.hpp>
#include "Res.h"

//loads texture to be used for tiles
sf::Texture worldTexture = loadTexture("Tile.png");
sf::Sprite sprite(worldTexture);
//every tile is 32 pixels wide and 32 tall
class Tile
{

	float x, y; 

public:
	Tile() 
	{ 
		x = NULL;
		y = NULL;
	}
	Tile(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	//both return the location of the last pixel on the tile on their respective axes
	int getEndX()
	{
		return x + 31;
	}
	int getEndY()
	{
		return y + 31;
	}

	//return the x or y coordinate of the tile's location
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}

	//draws tile onto window
	static void drawTile(sf::RenderWindow &window, Tile tile)
	{
		sprite.setPosition(tile.getX(), tile.getY());
		window.draw(sprite);
	}
};
