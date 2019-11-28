#ifndef __BRICKGAME_H__
#define __BRICKGAME_H__

#include<SFML/Graphics.hpp>
#include<ctime>
#include"NBrick.h"
#include"MBrick.h"
#include"HBrick.h"
#include"Ball.h"


class BrickGame
{
public:
	BrickGame();
	~BrickGame();
	void run();

private:
	void processEvents();
	//void handleInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time); //Change object
	void render(); //Draw object
	void createWall();
	void destroyWall();
	void randomizeBrickMap();
	void checkWallCollision();
	void updateBall(sf::Time);

	sf::RenderWindow mWindow;
	Ball newBall;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	Brick *Wall[wallWidth * wallHeight];
	int brickMap[wallHeight * wallWidth];
	/*{
		1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1,
		1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
	};*/
};



#endif // __BRICKGAME_H__