#pragma once
#include <SFML\Graphics.hpp>
#include "Physics.h"


class Entity
{
	float x, y, xVel, yVel;
	sf::Sprite sprite;

	//**not fields**
	float GRAVITY = .2f;
	bool jumpStarted = false;
	float fallVel = .5f;
	//**************

public:
	Entity(sf::Sprite sprite, float x, float y, float xVel, float yVel)
	{
		this->sprite = sprite;
		this->x = x;
		this->xVel = xVel;
		this->y = y;
		this->yVel = yVel;
	}

	//changes curretn sprite of entity
	void setSprite(sf::Sprite sprite)
	{
		this->sprite = sprite;
	}

	//return either the x or y coordienate of the entity's curent location
	float getX()
	{	
		return x;
	}
	float getY()
	{
		return y;
	}

	//used with game state class to move entity
	void moveRight()
	{
		if (testRight(x, y))
			x += xVel;
		else
			x -= xVel;
	}
	void moveLeft()
	{
		if (testLeft(x, y))
			x -= xVel;
		else
			x += xVel;
	}
	void jump()
	{
		if (testUp(x, y))
			y -= yVel;
		else
			y += yVel;
	}

	//used for when player walks off an edge
	void fall()
	{
		y += fallVel;
		fallVel += GRAVITY;
		
	}

	//draws entity
	void drawEntity(sf::RenderWindow &window)
	{
		sprite.setPosition(x, y);
		window.draw(sprite);
	}
	
	//resets jumpStarted
	void resetJumpStart()
	{
		fallVel = .5f;
	}

	void setX(float x)
	{
		this->x = x;
	}
	void setY(float y)
	{
		this->y = y;
	}
};