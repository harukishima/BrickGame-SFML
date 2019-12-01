#include "NBrick.h"

NBrick::NBrick()
{
	hpBar = HP = 1;
	score = 1;
	setFillColor(sf::Color::Green);
	brickTex[0].loadFromFile("resource\\03-Breakout-Tiles.png");
	brickTex[1].loadFromFile("resource\\04-Breakout-Tiles.png");
	setTexture(brickTex);
}
