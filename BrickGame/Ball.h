#ifndef __BALL_H__
#define __BALL_H__

#include<SFML/Graphics.hpp>
#include<random>
#include"MoveableObject.h"
#include"Global.h"


class Ball : public sf::CircleShape, public MoveableObject
{
private:
	sf::Texture tex;
public:
	Ball();
	virtual ~Ball() = default;
	virtual void defaultState();
};



#endif // !__BALL_H__