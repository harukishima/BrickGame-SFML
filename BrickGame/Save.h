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
	float speed;
	sf::Vector2f ballPos, ballDir;
	int* brickMap = NULL;
	Difficulty mode;

	Save();
	Save(Difficulty& mode, const int& life, const int& score, const float& speed, const sf::Vector2f& ballPos, const sf::Vector2f& ballDir, int* brickMap);
	virtual ~Save();

	bool loadFromFile(const std::string& path);
	void saveToFile(const std::string& path);
};




#endif // !__SAVE_H__