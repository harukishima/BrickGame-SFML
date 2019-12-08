#include "x2Brick.h"

x2Brick::x2Brick()
{
	hpBar = HP = 1;
	score = 0;
	setFillColor(sf::Color::Blue);
	brickTex[0].loadFromFile("resource\\hiclipart.com.png");
	brickTex[1].loadFromFile("resource\\hiclipart.com.png");
	setTexture(brickTex);
}

void x2Brick::paddleAction(Paddle& player)
{
	if(HP == 0)
		player.setScore(player.getScore() * 2);
}
