#pragma once
#include <SFML\Graphics.hpp>
//starts Main Menu
void startMainMenuState(sf::RenderWindow &window, sf::Sprite screen);

//Starts Game
void startGameState(sf::RenderWindow &window);

//Takes in input from keyboard and changes state based on the inputs
void updateState(sf::RenderWindow &window, sf::Sprite titleScreen);

//returns int representing the current state
int state();

