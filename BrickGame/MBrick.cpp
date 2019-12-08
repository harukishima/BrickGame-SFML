#include "MBrick.h"

MBrick::MBrick()
{
	hpBar = HP = 2;
	score = 2;
	setFillColor(sf::Color::Yellow);
	brickTex[0].loadFromFile("resource\\13-Breakout-Tiles.png");
	brickTex[1].loadFromFile("resource\\14-Breakout-Tiles.png");
	setTexture(brickTex);
}

