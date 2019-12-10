#ifndef __SAVE_H__
#define __SAVE_H__

#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Global.h"
#include"Date.h"



class Save
{
public:
	std::string timeSave;
	int life;
	int score;
	int speed;
	sf::Vector2f ballPos, ballDir;
	int* brickMap = NULL;

	Save();
	Save(const int& life, const int& score, const int& speed, const sf::Vector2f& ballPos, const sf::Vector2f& ballDir, int* brickMap);
	virtual ~Save();

	void loadFromFile(const std::string& path);
	void saveToFile(const std::string& path);
};




#endif // !__SAVE_H__