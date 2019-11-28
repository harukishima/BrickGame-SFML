#ifndef __BALL_H__
#define __BALL_H__

#include<SFML/Graphics.hpp>
#include"MoveableObject.h"
#include"Global.h"


class Ball : public sf::CircleShape, public MoveableObject
{
public:
	Ball();
	virtual ~Ball() = default;
};



#endif // !__BALL_H__