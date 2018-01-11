#pragma once
#include <SFML\Graphics.hpp>
#include <string>

//loads the texture "filename" and returns it
sf::Texture loadTexture(std::string filename);

//animates sprite based on how much time has passed
sf::IntRect animate(sf::IntRect source);

