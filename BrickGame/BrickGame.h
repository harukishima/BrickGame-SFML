#ifndef __BRICKGAME_H__
#define __BRICKGAME_H__

#include<SFML/Graphics.hpp>
#include<ctime>
#include<string>
#include<random>
#include<fstream>
#include"NBrick.h"
#include"MBrick.h"
#include"HBrick.h"
#include"x2Brick.h"
#include"MetalBrick.h"
#include"Ball.h"
#include"Paddle.h"
#include "Menu.h"
#include "EndMenu.h"
#include "PauseMenu.h"
#include "MainMenu.h"
#include "ScoreBoard.h"
#include "Save.h"
#include "DifficultyMenu.h"



class BrickGame
{
public:
	bool isMainMenu = true;
	bool isPause = false;
	bool isPlaying = false;
	bool isEnd = false;
	bool isNext = false;
	bool isDemo = false;
	bool isEndlessMode = false;
	bool isDiff = false;
	bool isScoreBoard = false;

	int process;

	BrickGame();
	~BrickGame();
	void run();

private:
	void processEvents();
	void handleInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time); //Change object
	void render(); //Draw object
	void createWall();
	void destroyWall();
	void randomizeBrickMap();
	void checkWallCollision();
	void updateBall(sf::Time);
	void updatePaddle(sf::Time);
	void checkProcessCondition();
	int checkBrickLeft();
	void restartGame();
	void processBot();
	void brickProcess();
	int* exportBrickMap();
	void saveGame(const std::string&);
	void loadGame(const std::string&);
	void readPossibility(const std::string& path, std::vector<int>& possibility);
	void loadDifficulty();
	
	std::vector<int> possibility;
	Difficulty mode = NORMAL;
	sf::RenderWindow mWindow;
	Ball newBall;
	int life = 3;
	sf::Text lifeText;
	void defaultBall();
	const sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	Brick* Wall[wallWidth * wallHeight] = {NULL};
	Paddle player;
	sf::Text scoreText;
	sf::Font font;
	sf::Text nextLevel;
	ScoreBoard highScore;
	int brickMap[wallHeight * wallWidth];
	//int totalBrick = 0;

	
	EndMenu endMenu;
	MainMenu mainMenu;
	PauseMenu pauseMenu;
	DifficultyMenu diffMenu;

};



#endif // __BRICKGAME_H__