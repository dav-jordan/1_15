#include <SFML/Graphics.hpp>
#include "StateMgr.h"
#include "Res.h"
#include "MapMgr.h"
#include "Entity.h"


/*
	*to do*
		-get maps to load -**
		-collision/physics
		-make title screen
		-make screen displaying current level before each level
		-more levels
		-make logo for myself
		-make website
		-RELEASE!!!!
		
*/
int main()
{
	//init window
	sf::RenderWindow window(sf::VideoMode(320, 448), "1_15");
	window.setFramerateLimit(60);
	//used to start game efficiently
	bool gameStarted = false;
	//load title screen
	sf::Texture texture = loadTexture("1_15title.png");
	sf::Sprite screen(texture);

	while (window.isOpen())
	{
		sf::Event event;

	

		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
		}
	
		if (!gameStarted)
		{
			startMainMenuState(window, screen);
			gameStarted = true;
		}


		updateState(window, screen);
		if (state() == 2)
			startMainMenuState(window, screen);
		window.display();
		}
	gameStarted = false;
	return 0;
}