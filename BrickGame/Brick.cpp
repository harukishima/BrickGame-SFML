#include "Brick.h"

Brick::Brick()
{
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(-2);
	setFillColor(sf::Color::Transparent);
	setSize(sf::Vector2f(mWidth * WinWidthRatio / wallWidth, mHeight * WinHeightRatio / wallHeight));
}

void Brick::checkCollision(Ball& ball)
{
	if (HP == 0) return;
	sf::Vector2f pos(ball.getPosition()), dir(ball.getDirection());
	float radius = ball.getRadius();
	sf::Vector2f brickPos(this->getPosition()), brickSize(this->getSize());
	if (pos.x >= brickPos.x && pos.x <= brickPos.x + brickSize.x && pos.y + radius >= brickPos.y && pos.y - radius <= brickPos.y + brickSize.y)
	{
		if (pos.y + radius < brickPos.y + brickSize.y)
		{
			pos.y = brickPos.y - radius;
		}
		if (pos.y - radius > brickPos.y)
		{
			pos.y = brickPos.y + brickSize.y + radius;
		}
		dir.y = -dir.y;
		damage();
	}
	if (pos.y >= brickPos.y && pos.y <= brickPos.y + brickSize.y && pos.x + radius >= brickPos.x && pos.x - radius <= brickPos.x + brickSize.x)
	{
		if (pos.x + radius < brickPos.x + brickSize.x)
		{
			pos.x = brickPos.x - radius;
		}
		if (pos.x - radius > brickPos.x)
		{
			pos.x = brickPos.x + brickSize.x + radius;
		}
		dir.x = -dir.x;
		damage();
	}
	ball.setPosition(pos);
	ball.setDirection(dir);
}

void Brick::damage()
{
	HP--;
}
