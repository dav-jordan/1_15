#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "StateMgr.h"
#include "Entity.h"
#include "MapMgr.h"
#include "Res.h"
#include <iostream>
using namespace std;

int currentLevel = 1;

sf::Texture sprites = loadTexture("TriangleCharacter.png");
sf::IntRect sourceSprite(0, 0, 32, 32);
sf::Sprite currentSprite(sprites, sourceSprite);
sf::Texture screen = loadTexture("GameOver.png");
sf::Sprite overScreen(screen);
sf::Texture completeScreen = loadTexture("Thanks.png");
sf::Sprite gameFinished(completeScreen);

Entity player = Entity::Entity(currentSprite, 0, 388, 5, 5.5);
bool wPressed = false;
bool levelCompleted = false;
bool fail = false;
bool gStart = false;
void initLevel()
{
	resetCounter();
	loadMap(("Level" + std::to_string(currentLevel) + ".txt").c_str());
}

void updateGameState(sf::RenderWindow &window)
{
	window.clear();
	if (player.getY() >= 448 - 32)
	{
		gameOver(window);
		gStart = false;
	
	}
	else
	{
		if (!gStart)
		{
			player.setX(50);
			player.setY(100);
			gStart = true;
		}

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			player.moveRight();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			player.moveLeft();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !wPressed)
		{
			player.jump();
			wPressed = true;
		}

		if (wPressed)
			player.jump();

		if (testDown(player.getX(), player.getY()))
			player.fall();
		else
		{
			player.resetJumpStart();
			wPressed = false;
		}

		if (player.getX() >= getFinishX() - 16 && player.getX() <= getFinishX() + 32 && player.getY() >= getFinishY() - 32 && player.getY() <= getFinishY())
		{
			levelCompleted = true;
		}
		player.drawEntity(window);
		drawMap(window);

		if (levelCompleted)
		{
			newLevel(window);
			if(currentLevel <= 15)
				levelCompleted = false;
		}
	}
}

void newLevel(sf::RenderWindow &window)
{
	if (currentLevel == 16)
		gameBeat(window);
	else 
	{
		player.setX(10);
		player.setY(340);
		window.clear();
		currentLevel++;
		initLevel();
	}
}

void gameOver(sf::RenderWindow &window)
{
	gStart = false;
	fail = true;
	currentLevel = 1;
	window.clear();
	window.draw(overScreen);
}

void gameFailed(bool failed)
{
	fail = failed;
}

void gameBeat(sf::RenderWindow &window)
{
	player.setX(400);
	window.clear();
	window.draw(gameFinished);
}