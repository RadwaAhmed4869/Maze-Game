#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define SPEED	1.5
#define WIDTH	200
#define HEIGHT  200
#define pSIZE	20

using namespace std;

class Player
{
private:
	sf::Texture pTexture;
	sf::CircleShape pCircle;

public:
	Player(){
		// Default constructor
	}

	Player(string imgDirct = "blue.png")
	{
		if (!pTexture.loadFromFile(imgDirct))
		{
			std::cerr << "Error\n";
		}
		pCircle.setTexture(&pTexture);
		pCircle.setRadius(pSIZE);
	}

	void drawPlayer(sf::RenderWindow &window);
	void movePlayer(char, float);
	void screenCollision();
};

#endif

