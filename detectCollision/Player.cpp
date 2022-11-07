#include "Player.h"

using namespace std;

void Player::drawPlayer(sf::RenderWindow &window)
{
	window.draw(pCircle);
}

void Player::movePlayer(char direction, float moveSpeed)
{
	//cout << "Player moving\n";
	if (direction == 'u') {
		pCircle.move(0, -moveSpeed);
	}
	else if (direction == 'd') {
		pCircle.move(0, moveSpeed);
	}
	else if (direction == 'r') {
		pCircle.move(-moveSpeed, 0);
	}
	else if (direction == 'l') {
		pCircle.move(moveSpeed, 0);
	}
}

void Player::screenCollision()
{
	// left collision
	if (pCircle.getPosition().x < 0)
	{
		pCircle.setPosition(0, pCircle.getPosition().y);
	}
	// up collision
	if (pCircle.getPosition().y < 0)
	{
		pCircle.setPosition(pCircle.getPosition().x, 0);
	}
	// right collision
	if (pCircle.getPosition().x > WIDTH - 2 * pSIZE)
	{
		pCircle.setPosition(WIDTH - 2 * pSIZE, pCircle.getPosition().y);
	}
	// down collision
	if (pCircle.getPosition().y > HEIGHT - 2 * pSIZE)
	{
		pCircle.setPosition(pCircle.getPosition().x, HEIGHT - 2 * pSIZE);
	}
}

