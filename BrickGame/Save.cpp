#include "Save.h"

Save::Save()
{
	brickMap = NULL;
}

Save::Save(const int& slife, const int& sscore, const int& sspeed, const sf::Vector2f& sballPos, const sf::Vector2f& sballDir, int* sbrickMap)
{
	stringstream date;
	Date cur; cur.Now();
	date << cur;
	std::getline(date, timeSave);
	life = slife;
	score = sscore;
	speed = speed;
	ballPos = sballPos;
	ballDir = sballDir;
	brickMap = sbrickMap;
}

Save::~Save()
{
	if (brickMap != NULL)
	{
		delete brickMap;
	}
}

void Save::loadFromFile(const std::string& path)
{
	std::ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cout << "File is not exist" << std::endl;
		return;
	}
	std::string tmp;
	char delim = ',';
	std::getline(file, tmp, delim);
	timeSave = tmp;
	std::getline(file, tmp, delim);
	life = std::stoi(tmp);
	std::getline(file, tmp, delim);
	score = std::stoi(tmp);
	std::getline(file, tmp, delim);
	ballPos.x = std::stof(tmp);
	std::getline(file, tmp, delim);
	ballPos.y = std::stof(tmp);
	std::getline(file, tmp, delim);
	ballDir.x = std::stof(tmp);
	std::getline(file, tmp, delim);
	ballDir.y = std::stof(tmp);
	std::getline(file, tmp, delim);
	speed = std::stof(tmp);
	if(brickMap == NULL)
		brickMap = new int[wallWidth * wallHeight];
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			std::getline(file, tmp, delim);
			brickMap[i * wallWidth + j] = std::stoi(tmp);
		}
	file.close();
}

void Save::saveToFile(const std::string& path)
{
	std::ofstream file;
	file.open(path);
	if (!file.is_open()) return;
	file << timeSave << "," << life << "," << score << "," << ballPos.x << "," << ballPos.y << "," << ballDir.x << "," << ballDir.y << "," << speed;
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			file << "," << brickMap[i * wallWidth + j];
		}
	file.close();
}
