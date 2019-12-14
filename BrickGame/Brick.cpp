#include "Brick.h"

Brick::Brick()
{
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(-2);
	setFillColor(sf::Color::Transparent);
	setSize(sf::Vector2f(mWidth * WinWidthRatio / wallWidth, mHeight * WinHeightRatio / wallHeight));
	//50
	//26.6
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
		ting.play();
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
		ting.play();
	}
	ball.setPosition(pos);
	ball.setDirection(dir);
}

int Brick::getHP()
{
	return HP;
}

int Brick::getScore()
{
	return score;
}

void Brick::damage()
{
	HP--;
	if (HP <= hpBar / 2.f)
		changeTexture();
}

void Brick::changeTexture()
{
	if (HP != 0)
	{
		setTexture(&brickTex[1]);
	}
}

void Brick::paddleAction(Paddle& player)
{
	if (HP == 0)
	{
		player.setScore(player.getScore() + getScore());
	}
}
