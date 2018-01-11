#include <SFML\Graphics.hpp>
#include "Res.h"
#include <string>

sf::Texture loadTexture(std::string filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);
	return texture;
}

sf::IntRect animate(sf::IntRect source)
{
	sf::IntRect newSource = source;


	if (newSource.top == 128)
			newSource.top = 0;

	if (newSource.left == 32)
	{
		newSource.left = 0;
		newSource.top += 32;
	}
	else
		newSource.left += 32;

	
	return newSource;

}

