#include "Ball.h"

Ball::Ball()
{
	mSpeed = 1000;
	mDirection.x = sqrt(2) / 2;
	mDirection.y = sqrt(2) / 2;
	mDirection = normalizeVector(mDirection);
	setRadius(10);
	setOrigin(getRadius(), getRadius());
	setPosition(mWidth / 2.f, mHeight * (3.f / 4.f));
	tex.loadFromFile("resource\\58-Breakout-Tiles.png");
	setTexture(&tex);
}

void Ball::defaultState()
{
	setSpeed(500);
	setPosition(mWidth / 2.f, mHeight * (3.f / 4.f));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniform_distance(1, std::nextafter(360, DBL_MAX));
	float angle;
	sf::Vector2f direction;

	//Make ball move random when started
	do {
		angle = uniform_distance(gen);
		direction = MoveableObject::rolateVector(getDirection(), angle);
		direction = MoveableObject::normalizeVector(direction);
		angle = MoveableObject::angleInDegree(direction);
		//Ensure ball angle not too vertical
	} while (!(angle < -45 && angle > -135)); //(angle > -45 && angle < 45) || (angle < -135 && angle > 135)
	setDirection(direction);
}
