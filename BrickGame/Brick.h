#ifndef __BRICK_H__
#define __BRICK_H__

#include<SFML/Graphics.hpp>
#include"Global.h"
#include"Ball.h"
#include"Paddle.h"

class Brick : 
	public sf::RectangleShape
{
protected:
	int HP = 0, hpBar = 0;
	int score = 0;
	sf::Texture brickTex[2];
public:
	Brick();
	bool isAlive(){return HP;}
	void checkCollision(Ball&);
	int getHP();
	int getScore();
	void damage();
	void changeTexture();
	void paddleAction(Paddle&);
	//void ballAction();
	virtual ~Brick() = default;
	virtual int getType() { return 0; }
};




#endif // !__BRICK_H__



