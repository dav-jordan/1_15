#pragma once

//initializes current level
void initLevel();

//updates the game state
void updateGameState(sf::RenderWindow &window);

//increments the current level
void newLevel(sf::RenderWindow &window);

//ends game whan player dies
void gameOver(sf::RenderWindow &window);

//returns true if the player has lost
void gameFailed(bool failed);

//called when last level is completed
void gameBeat(sf::RenderWindow &window);