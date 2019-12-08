#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Global.h"

class ScoreBoard
{
public:
	sf::Font font;
	sf::Text title;
	std::vector<sf::Text> scoreText;
	std::vector<int> score;

	ScoreBoard();
	void update();
	void load(const std::string& path);
	void save(const std::string& path);
	void addScore(int newScore);
};




#endif // !__SCOREBOARD_H__