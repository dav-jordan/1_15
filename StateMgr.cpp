#include "StateMgr.h"
#include "GameState.h"
#include "MapMgr.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Res.h"

using namespace std;

int currentState = 2;

void startMainMenuState(sf::RenderWindow &window, sf::Sprite screen)
{
	
	currentState = 2;
	window.clear();
	window.draw(screen);
}


void startGameState(sf::RenderWindow &window)
{
	initLevel();
	currentState = 0;
}

void updateState(sf::RenderWindow &window, sf::Sprite titleScreen)
{
	//--------------------------------------
	bool enterPressed = false;
	bool escPressed = false;
	//sf::Texture menuTexture = loadTexture("MainMenu.png");
	//f::Sprite menuSprite(menuTexture);
	//menuSprite.setPosition(0, 0);

	//go from menu to game
	while (currentState == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		enterPressed = true;

	if (enterPressed)
	{
		startGameState(window);
		currentState = 0;
		enterPressed = false;
	}
	
	//go from game state to main menu
	if (currentState == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		startMainMenuState(window, titleScreen);
		gameFailed(false);
	}

	//------------------------------------------
	if (currentState == 0)
		updateGameState(window);


}

int state()
{
	return currentState;
}
