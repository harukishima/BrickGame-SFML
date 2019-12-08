#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{
	scoreText.resize(10);
	score.resize(10);
	font.loadFromFile("resource\\Retro Gaming.ttf");
	title.setFont(font);
	title.setString("SCORE BOARD");
	title.setPosition(sf::Vector2f(mWidth / 2 - 125, 100));
	for (int i = 0; i < scoreText.size(); i++)
	{
		scoreText[i].setFont(font);
		score[i] = 0;
		scoreText[i].setString(std::to_string(i + 1) + ".\t\t" + std::to_string(score[i]));
		scoreText[i].setPosition(sf::Vector2f(mWidth / 2 - 150, 200 + i * 30));
	}
}

void ScoreBoard::update()
{
	for (int i = 0; i < scoreText.size(); i++)
	{
		scoreText[i].setString(std::to_string(i + 1) + ".\t\t" + std::to_string(score[i]));
	}
}

void ScoreBoard::load(const std::string& path)
{
	std::ifstream file(path);
	while (!file.is_open())
	{
		std::cout << "Cannot read scoreboard" << std::endl;
		return;
	}
	std::string tmp;
	for (int i = 0; i < score.size(); i++)
	{
		std::getline(file, tmp);
		score[i] = std::stoi(tmp);
	}
	file.close();
	update();
}

void ScoreBoard::save(const std::string& path)
{
	std::ofstream file(path);
	if (!file.is_open())
	{
		std::cout << "Cannot save scoreboard" << std::endl;
		return;
	}
	for (int i = 0; i < score.size(); i++)
	{
		file << score[i] << std::endl;
	}
	file.close();
}

void ScoreBoard::addScore(int newScore)
{
	for (int i = 0; i < score.size(); i++)
	{
		if (newScore > score[i])
		{
			for (int j = score.size() - 2; j > i; j--)
			{
				score[j] = score[j - 1];
			}
			score[i] = newScore;
			break;
		}
	}
	update();
}
