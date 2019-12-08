#include "MetalBrick.h"

MetalBrick::MetalBrick()
{
	hpBar = HP = INT_MAX;
	score = 0;
	setFillColor(sf::Color(169,169,169));
	brickTex[0].loadFromFile("resource\\metal.png");
	brickTex[1].loadFromFile("resource\\metal.png");
	setTexture(brickTex);
}
