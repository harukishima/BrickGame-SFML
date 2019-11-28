#ifndef __BRICK_H__
#define __BRICK_H__

#include<SFML/Graphics.hpp>
#include"Global.h"
#include"Ball.h"

class Brick : 
	public sf::RectangleShape
{
protected:
	int HP = 0;
	int score = 0;
public:
	Brick();
	bool isAlive(){return HP;}
	void checkCollision(Ball&);
	void damage();
	virtual ~Brick() = default;
};




#endif // !__BRICK_H__



