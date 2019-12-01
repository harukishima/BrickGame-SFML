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
}
