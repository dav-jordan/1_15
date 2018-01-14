#pragma once
#include <SFML\Graphics.hpp>
//loads level from txt file
void loadMap(const char *filename);

//draws the level
void drawMap(sf::RenderWindow &window);

//returns the part of the tilemap that would be at (x, y)
sf::Vector2i getMap(float x, float y);

//resets loadCounter
void resetCounter();

//return coordinates of the current level's end
float getFinishX();
float getFinishY();