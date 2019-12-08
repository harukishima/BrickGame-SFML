#include "HBrick.h"

HBrick::HBrick()
{
	hpBar = HP = 3;
	score = 3;
	setFillColor(sf::Color::Red);
	brickTex[0].loadFromFile("resource\\07-Breakout-Tiles.png");
	brickTex[1].loadFromFile("resource\\08-Breakout-Tiles.png");
	setTexture(brickTex);
}


