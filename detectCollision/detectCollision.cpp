#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Collision Detection");
	// useful to try collision detection with lower frame rate
	window.setFramerateLimit(120);

	// delta time
	float dt;
	sf::Clock dt_clock;

	const float gridsize = 50.f;
	// player speed
	// probably later I will create player class in seperate file
	const float speed = 100.f;
	sf::Vector2f velocity;

	// rectangle block
	// float side = 40;
	// sf::RectangleShape shape(sf::Vector2f(side, side));
	// shape.setFillColor(sf::Color::White);

	// player
	Player myPlayer("blue.png");
	float moveSpeed = SPEED;

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			myPlayer.movePlayer('u', moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			myPlayer.movePlayer('d', moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			myPlayer.movePlayer('l', moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			myPlayer.movePlayer('r', moveSpeed);
		}

		// Screen collision 
		myPlayer.screenCollision();

		window.clear();
		myPlayer.drawPlayer(window);
		//window.draw(shape);
		window.display();
	}
	return 0;
}