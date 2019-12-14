#include "Paddle.h"

Paddle::Paddle()
{
	setSize(sf::Vector2f(100.f, 30.f));
	setPosition(sf::Vector2f(mWidth / 2.f - getSize().x / 2.f, mHeight - getSize().y - 20));
	mSpeed = 500;
	normal[0].loadFromFile("resource\\50-Breakout-Tiles.png");
	normal[1].loadFromFile("resource\\51-Breakout-Tiles.png");
	normal[2].loadFromFile("resource\\52-Breakout-Tiles.png");
	setTexture(&normal[0]);
	buff.loadFromFile("resource\\bounce.wav");
	bounce.setBuffer(buff);
}

void Paddle::defaultState()
{
	setSize(sf::Vector2f(100.f, 30.f));
	setPosition(sf::Vector2f(mWidth / 2.f - getSize().x / 2.f, mHeight - getSize().y - 20));
	mDirection = sf::Vector2f(0, 0);
	isLeft = isRight = false;
	mSpeed = 500;
}

void Paddle::setScore(const int& score)
{
	mScore = score;
}

int Paddle::getScore()
{
	return mScore;
}

void Paddle::defaultPaddle()
{
	setSize(sf::Vector2f(10.f, 100.f));

	mDirection = sf::Vector2f(0, 0);
}

void Paddle::setLeftState(bool state)
{
	isLeft = state;
}

void Paddle::setRightState(bool state)
{
	isRight = state;
}

bool Paddle::getLeftState()
{
	return isLeft;
}

bool Paddle::getRightState()
{
	return isRight;
}

bool Paddle::isInScreen()
{
	sf::Vector2f pos = getPosition();
	if (pos.x >= 0 && pos.x <= mWidth - getSize().x)
		return true;
	return false;
}

void Paddle::processMove()
{
	sf::Vector2f pos = getPosition();
	if (isLeft && pos.x >= 0)
	{
		setDirection(sf::Vector2f(-1, 0));
	}
	else if (isRight && pos.x <= mWidth - getSize().x)
	{
		setDirection(sf::Vector2f(1, 0));
	}
	else
	{
		setDirection(sf::Vector2f(0, 0));
	}
	
}

void Paddle::checkCollision(Ball& ball)
{
	sf::Vector2f pos(ball.getPosition()), dir(ball.getDirection());
	float radius = ball.getRadius();
	sf::Vector2f paddlePos(this->getPosition()), paddleSize(this->getSize());
	//Random
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniform_distance(1, std::nextafter(30, DBL_MAX));
	float angle;

	//Make ball move random when started
	//do {
	//	angle = uniform_distance(gen);
	//	direction = MoveableObject::rolateVector(getDirection(), angle);
	//	direction = MoveableObject::normalizeVector(direction);
	//	angle = MoveableObject::angleInDegree(direction);
	//	//Ensure ball angle not too vertical
	//} while ((angle > -45 && angle < 45) || (angle < -135 && angle > 135));

	/*angle = uniform_distance(gen);
	if (-angle - MoveableObject::angleInDegree(dir) > 170)
	{
		dir = MoveableObject::rolateVector(dir, -angle);
	}*/

	if (pos.x >= paddlePos.x && pos.x <= paddlePos.x + paddleSize.x && pos.y + radius >= paddlePos.y && pos.y - radius <= paddlePos.y + paddleSize.y) //Trên và dưới
	{
		if (pos.y + radius < paddlePos.y + paddleSize.y)
		{
			pos.y = paddlePos.y - radius;
		}
		if (pos.y - radius > paddlePos.y)
		{
			pos.y = paddlePos.y + paddleSize.y + radius;
		}
		dir.y = -dir.y;
		if (ball.getSpeed() < maxBallSpeed)
		{
			ball.setSpeed(ball.getSpeed() + ball.getSpeed() * 0.1); //Tăng tốc độ lên 10%
		}
		angle = uniform_distance(gen);
		if (getDirection().x == -1) //Nếu paddle đi sang trái, xoay góc phản xạ của ball một góc angle ngược chiều kim đồng hồ
		{
			if (MoveableObject::angleInDegree(dir) - angle > -170)
			{
				dir = MoveableObject::rolateVector(dir, -angle);
			}
		}
		if (getDirection().x == 1) ///Nếu paddle đi sang phải, xoay góc phản xạ của ball một góc angle theo chiều kim đồng hồ
		{
			if (MoveableObject::angleInDegree(dir) + angle < -10)
			{
				dir = MoveableObject::rolateVector(dir, angle);
			}
		}
		bounce.play();
	}
	if (pos.y >= paddlePos.y && pos.y <= paddlePos.y + paddleSize.y && pos.x + radius >= paddlePos.x && pos.x - radius <= paddlePos.x + paddleSize.x) //Trái và phải
	{
		if (pos.x + radius < paddlePos.x + paddleSize.x)
		{
			pos.x = paddlePos.x - radius;
		}
		if (pos.x - radius > paddlePos.x)
		{
			pos.x = paddlePos.x + paddleSize.x + radius;
		}
		dir.x = -dir.x;
		dir.y = -dir.y;
		if (ball.getSpeed() < maxBallSpeed)
		{
			ball.setSpeed(ball.getSpeed() + ball.getSpeed() * 0.1);
		}
		bounce.play();
	}
	ball.setPosition(pos);
	ball.setDirection(dir);
}

void Paddle::animate()
{
	setTexture(&normal[i % 3]);
	i++;
	if (i > 100000) i = 0;
}
