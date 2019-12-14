#ifndef __PADDLE_H__
#define __PADDLE_H__

#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include"MoveableObject.h"
#include"Global.h"
#include"Ball.h"

class Paddle : public sf::RectangleShape, public MoveableObject
{
private:
	bool isLeft = false; //true: paddle move left
	bool isRight = false; //true: paddle move right
	int mScore = 0; //Player's score
	sf::SoundBuffer buff;
	sf::Sound bounce;
	sf::Texture normal[3];
	int i = 0;
public:
	Paddle();
	virtual ~Paddle() = default;
	virtual void defaultState();
	void setScore(const int&);
	int getScore();

	void defaultPaddle();
	void setLeftState(bool state);
	void setRightState(bool state);
	bool getLeftState();
	bool getRightState();
	bool isInScreen();
	void processMove();
	void checkCollision(Ball&);
	void animate();

};


#endif // !__PADDLE_H__