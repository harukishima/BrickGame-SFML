#include "BrickGame.h"
#include "Global.h"

BrickGame::BrickGame() :
	mWindow(sf::VideoMode(mWidth, mHeight), "Brick Game")
{
	mWindow.setKeyRepeatEnabled(false);
	newBall.defaultState();
	font.loadFromFile("resource\\Retro Gaming.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setPosition(sf::Vector2f(50, 15));
	lifeText.setFont(font);
	lifeText.setCharacterSize(30);
	lifeText.setPosition(sf::Vector2f(400, 15));
	highScore.load("highscore.txt");
	readPossibility("Difficulty\\NORMAL.txt", possibility);
	loadSaveFile("Save");
	//randomizeBrickMap(); //Tạo ngẫu nhiên tilemap
	//createWall(); //Xây dựng tường gạch
	
}

BrickGame::~BrickGame()
{
	destroyWall();
	highScore.save("highscore.txt");
}

void BrickGame::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
		/*processEvents();
		update(clock.restart());
		render();*/
	}
}

void BrickGame::processEvents()
{
	sf::Event ev;
	while (mWindow.pollEvent(ev))
	{
		switch (ev.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			handleInput(ev.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handleInput(ev.key.code, false);
			break;
		}
	}
}

void BrickGame::handleInput(sf::Keyboard::Key key, bool isPressed)
{
		if (isPlaying && key == sf::Keyboard::Left && !isDemo)
		{
			player.setLeftState(isPressed);
		}
		if (isPlaying && key == sf::Keyboard::Right && !isDemo)
		{
			player.setRightState(isPressed);
		}
		if (isPlaying && key == sf::Keyboard::Escape)
		{
			isPause = true;
			isPlaying = false;
		}
		if (isDemo && key == sf::Keyboard::Escape)
		{
			isPause = true;
			//isDemo = false;
		}

		if (isPressed)
		{
			if (isMainMenu)
			{
				mainMenu.changeState(key);
				if (key == sf::Keyboard::Enter)
				{
					switch (mainMenu.getState())
					{
					case 1:
					{
						isLoad = true;
						isMainMenu = false;
						svMenu.title.setString("Load game");
						break;
					}
					case 2:
					{
						isMainMenu = false;
						isPlaying = true;
						// endless mode
						restartGame();
						randomizeBrickMap();
						//loadGame("Save\\savegame1.txt");
						createWall();
						break;
					}
					case 3:
					{
						isMainMenu = false;
						// difficulty
						isDiff = true;
						break;
					}
					case 4:
					{
						isMainMenu = false;
						isPlaying = true;
						isDemo = true;
						restartGame();
						randomizeBrickMap();
						createWall();
						player.setSpeed(1000);
						// demo
						break;
					}
					case 5:
					{
						isMainMenu = false;
						//isPlaying = true;
						// enter scoreboard
						isScoreBoard = true;
						break;
					}
					case 6:
					{
						mWindow.close();
						break;
					}
					}
				}

			}
			else if (isScoreBoard)
			{
				if (key == sf::Keyboard::Escape)
				{
					isScoreBoard = false;
					isMainMenu = true;
				}
			}
			else if (isEnd)
			{
				endMenu.changeState(key);
				restartGame();
				destroyWall();
				isPlaying = false;
				isDemo = false;
				if (endMenu.getState() == 1 && key == sf::Keyboard::Enter)
				{
					isMainMenu = true;
					isEnd = false;
				}
				else if (endMenu.getState() == 2 && key == sf::Keyboard::Enter)
				{
					isEnd = false;
					isScoreBoard = true;
					// enter scoreboard
				}
			}
			else if (isPause)
			{
				pauseMenu.changeState(key);
				if (key == sf::Keyboard::Enter)
				{
					switch (pauseMenu.getState())
					{
						case 1:
						{

							isPlaying = true;
							isPause = false;
							break;
						}
						case 2:
						{
							isPause = false;
							isSave = true;
							break;
						}
						case 3:
						{
							isMainMenu = true;
							isPlaying = false;
							isPause = false;
							isDemo = false;
							destroyWall();
							restartGame();
							break;
						}
					}
				}
			}
			else if (isDiff)
			{
				diffMenu.changeState(key);
				if (key == sf::Keyboard::Enter)
				{
					switch (diffMenu.getState())
					{
					case 1:
						mode = EASY;
						break;
					case 2:
						mode = NORMAL;
						break;
					case 3:
						mode = HARD;
						break;
					}
					loadDifficulty();
				}
				if (key == sf::Keyboard::Escape)
				{
					isDiff = false;
					isMainMenu = true;
				}
			}
			else if (isLoad)
			{
				svMenu.changeState(key);
				if (key == sf::Keyboard::Enter)
				{
					int state = svMenu.getState();
					if (save[state - 1] != NULL)
					{
						applySave(*save[state - 1]);
						isPlaying = true;
						isLoad = false;
						createWall();
					}
				}
				if (key == sf::Keyboard::Escape)
				{
					isLoad = false;
					isMainMenu = true;
				}
			}
			else if (isSave)
			{
				svMenu.changeState(key);
				if (key == sf::Keyboard::Enter)
				{
					int state = svMenu.getState();
					createSave(state - 1);
				}
				if (key == sf::Keyboard::Escape)
				{
					isSave = false;
					isPause = true;
				}
			}
		}
}

void BrickGame::update(sf::Time TimePerFrame)
{
	if (isPlaying)
	{
		checkWallCollision();
		updateBall(TimePerFrame);
		player.processMove();
		player.checkCollision(newBall);
		updatePaddle(TimePerFrame);
		player.animate();
		scoreText.setString("Score: " + std::to_string(player.getScore()));
		lifeText.setString("Life: " + std::to_string(life));
		brickProcess();
		checkProcessCondition();
		/*if (isNext)
		{
			destroyWall();
			randomizeBrickMap();
			createWall();
			isNext = false;
		}*/
	}
	if (isDemo && isPlaying)
	{
		processBot();
	}
	else if (isMainMenu)
	{
		mainMenu.updateMenu();
	}
	else if (isPause)
	{
		pauseMenu.updateMenu();
	}
	else if (isEnd)
	{
		endMenu.updateMenu();
	}
	else if (isDiff)
	{
		diffMenu.updateMenu();
		switch (mode)
		{
		case EASY:
			diffMenu.curDiff.setString("Current mode: EASY");
			break;
		case NORMAL:
			diffMenu.curDiff.setString("Current mode: NORMAL");
			break;
		case HARD:
			diffMenu.curDiff.setString("Current mode: HARD");
			break;
		default:
			break;
		}
	}
	else if (isLoad || isSave)
	{
		svMenu.updateMenu();
	}
}

void BrickGame::render()
{
	mWindow.clear();
	if (isPlaying)
	{
		for (int i = 0; i < wallHeight; i++)
		{
			for (int j = 0; j < wallWidth; j++)
			{
				if (Wall[i * wallWidth + j] > 0 && Wall[i * wallWidth + j]->isAlive())
					mWindow.draw(*Wall[i * wallWidth + j]); //Vẽ từng viên gạch
			}
		}
		mWindow.draw(newBall); //Vẽ bóng
		mWindow.draw(player); //Vẽ người chơi
		mWindow.draw(scoreText); //Vẽ điểm số
		mWindow.draw(lifeText);
		//if (isNext)
		//{
		//	for (int i = 0; i < wallHeight; i++)
		//	{
		//		for (int j = 0; j < wallWidth; j++)
		//		{
		//			if (Wall[i * wallWidth + j] > 0 && Wall[i * wallWidth + j]->isAlive())
		//				mWindow.draw(*Wall[i * wallWidth + j]); //Vẽ từng viên gạch
		//		}
		//	}
		//}
	}
	else if (isMainMenu)
	{
		//Draw main menu
		mWindow.draw(mainMenu.title);
		mWindow.draw(mainMenu.firstText);
		mWindow.draw(mainMenu.secondText);
		mWindow.draw(mainMenu.thirdText);
		mWindow.draw(mainMenu.fourthText);
		mWindow.draw(mainMenu.fifthText);
		mWindow.draw(mainMenu.sixthText);
	}
	else if (isPause)
	{
		mWindow.draw(pauseMenu.upperText);
		mWindow.draw(pauseMenu.middleText);
		mWindow.draw(pauseMenu.underText);
	}
	else if (isEnd)
	{
		mWindow.draw(endMenu.resultText);
		mWindow.draw(endMenu.leftText);
		mWindow.draw(endMenu.rightText);
	}
	else if (isScoreBoard)
	{
		mWindow.draw(highScore.title);
		for (int i = 0; i < 10; i++)
		{
			mWindow.draw(highScore.scoreText[i]);
		}
	}
	else if (isDiff)
	{
		mWindow.draw(diffMenu.title);
		mWindow.draw(diffMenu.curDiff);
		mWindow.draw(diffMenu.firstText);
		mWindow.draw(diffMenu.secondText);
		mWindow.draw(diffMenu.thirdText);
	}
	else if (isLoad || isSave)
	{
		mWindow.draw(svMenu.title);
		for (int i = 0; i < 7; i++)
		{
			mWindow.draw(svMenu.text[i]);
		}
	}
	mWindow.display();
}

void BrickGame::createWall()
{
	for (int i = 0; i < wallHeight; i++)
	{
		for (int j = 0; j < wallWidth; j++)
		{
			/*if (brickMap[i * wallWidth + j] == 1)
			{
				Wall[i * wallWidth + j] = new NBrick;
			}
			else if (brickMap[i * wallWidth + j] == 2)
			{
				Wall[i * wallWidth + j] = new MBrick;
			}
			if (brickMap[i * wallWidth + j] == 3)
			{
				Wall[i * wallWidth + j] = new HBrick;
			}
			else
			{
				Wall[i * wallWidth + j] = new Brick;
			}*/
			switch (brickMap[i * wallWidth + j])
			{
			case 1:
				Wall[i * wallWidth + j] = new NBrick;
				break;
			case 2:
				Wall[i * wallWidth + j] = new MBrick;
				break;
			case 3:
				Wall[i * wallWidth + j] = new HBrick;
				break;
			case 4:
				Wall[i * wallWidth + j] = new x2Brick;
				break;
			case 5:
				Wall[i * wallWidth + j] = new MetalBrick;
				break;
			default:
				Wall[i * wallWidth + j] = new Brick;
				break;
			}
			sf::Vector2f tmp = Wall[i * wallWidth + j]->getSize();
			Wall[i * wallWidth + j]->setPosition(sf::Vector2f(tmp.x * j, board + tmp.y * i));
		}
	}
}

void BrickGame::destroyWall()
{
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			if (Wall[i * wallWidth + j] != NULL)
			{
				delete Wall[i * wallWidth + j];
				Wall[i * wallWidth + j] = NULL;
			}
		}
}

void BrickGame::randomizeBrickMap()
{
	//srand((int)time(0));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniform_distance(1, std::nextafter(100, DBL_MAX));
	int prob;
	for(int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			//brickMap[i * wallWidth + j] = rand() % 6;
			prob = uniform_distance(gen);
			/*if (prob <= 30)
				brickMap[i * wallWidth + j] = 0;
			else if (prob <= 65)
				brickMap[i * wallWidth + j] = 1;
			else if (prob <= 80)
				brickMap[i * wallWidth + j] = 2;
			else if (prob <= 90)
				brickMap[i * wallWidth + j] = 3;
			else if (prob <= 95)
				brickMap[i * wallWidth + j] = 4;
			else
				brickMap[i * wallWidth + j] = 5;*/
			if (prob <= possibility[0])
				brickMap[i * wallWidth + j] = 0;
			else if (prob <= possibility[0] + possibility[1])
				brickMap[i * wallWidth + j] = 1;
			else if (prob <= possibility[0] + possibility[1] + possibility[2])
				brickMap[i * wallWidth + j] = 2;
			else if (prob <= possibility[0] + possibility[1] + possibility[2] + possibility[3])
				brickMap[i * wallWidth + j] = 3;
			else if (prob <= possibility[0] + possibility[1] + possibility[2] + possibility[3] + possibility[4])
				brickMap[i * wallWidth + j] = 4;
			else
				brickMap[i * wallWidth + j] = 5;
		}
}

void BrickGame::checkWallCollision()
{
	sf::Vector2f pos(newBall.getPosition());
	sf::Vector2f dir(newBall.getDirection());
	if (pos.x - newBall.getRadius() <= 0) //Chạm tường trái
	{
		dir.x = -dir.x;
		pos.x = newBall.getRadius();
	}
	if (pos.y - board - newBall.getRadius() <= 0) //Chạm tường phải
	{
		dir.y = -dir.y;
		pos.y = board + newBall.getRadius();
	}
	if (pos.x + newBall.getRadius() >= mWidth * WinWidthRatio) //Chạm tường trên
	{
		dir.x = -dir.x;
		pos.x = mWidth * WinWidthRatio - newBall.getRadius();
	}
	//if (pos.y + newBall.getRadius() >= mHeight) //For testing purpose, chạm tường dưới
	//{
	//	dir.y = -dir.y;
	//	pos.y = mHeight - newBall.getRadius();
	//}
	newBall.setDirection(dir);
	newBall.setPosition(pos);
	if (pos.y - newBall.getRadius() >= mHeight) //chạm tường dưới
	{
		/*dir.y = -dir.y;
		pos.y = mHeight - newBall.getRadius();*/
		life--;
		newBall.defaultState();

	}
}

void BrickGame::updateBall(sf::Time TimePerFrame)
{
	sf::Vector2f movement;
	movement = newBall.getDirection() * newBall.getSpeed() * TimePerFrame.asSeconds();
	newBall.move(movement);
}

void BrickGame::updatePaddle(sf::Time TimePerFrame)
{
	sf::Vector2f movement;
	movement = player.getDirection() * player.getSpeed() * TimePerFrame.asSeconds();
	player.move(movement);
}

void BrickGame::defaultBall()
{
	newBall.setSpeed(500);
	newBall.setPosition(mWidth / 2.f, mHeight * (3.f / 4.f));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniform_distance(-180, std::nextafter(180, DBL_MAX));
	float angle;
	float x, y;
	sf::Vector2f direction;

	//Make ball move random when started
	do {
		angle = uniform_distance(gen);
		direction = MoveableObject::rolateVector(newBall.getDirection(), angle);
		direction = MoveableObject::normalizeVector(direction);
		angle = MoveableObject::angleInDegree(direction);
		//Ensure ball angle not too vertical
	} while ((angle > -45 && angle < 45) || (angle < -135 && angle > 135));
	newBall.setDirection(direction);
}

void BrickGame::checkProcessCondition()
{
	if (life <= 0)
	{
		isPlaying = false;
		isEnd = true;
		if(!isDemo)
			highScore.addScore(player.getScore());
	}
	else if (life > 0 && checkBrickLeft() == 0)
	{
		destroyWall();
		randomizeBrickMap();
		createWall();
		newBall.defaultState();
		//isNext = true;
	}
}

int BrickGame::checkBrickLeft()
{
	int check = 0;
	for (int i = 0; i < wallHeight; i++)
	{
		for (int j = 0; j < wallWidth; j++)
		{
			if (Wall[i * wallWidth + j]->getHP() > 0 && Wall[i * wallWidth + j]->getType() != 5)
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			break;
		}
	}
	return check;
}

void BrickGame::restartGame()
{
	player.setScore(0);
	newBall.defaultState();
	player.defaultState();
	life = defaultLife;
}

void BrickGame::processBot()
{
	sf::Vector2f pos(newBall.getPosition());
	sf::Vector2f paddlePos(player.getPosition());
	sf::Vector2f pSize(player.getSize());
	if (pos.x > paddlePos.x + pSize.x * (3.f / 4.f) && paddlePos.x + pSize.x < mWidth)
	{
		player.setRightState(true);
		player.setLeftState(false);
		if (paddlePos.x + pSize.x >= mWidth)
			player.setPosition(sf::Vector2f(mWidth - 1, paddlePos.y));
		if (paddlePos.x <= 0)
			player.setPosition(sf::Vector2f(1, paddlePos.y));
	}
	else if (pos.x < paddlePos.x + pSize.x * (1.f / 4.f) && paddlePos.x > 0)
	{
		player.setLeftState(true);
		player.setRightState(false);
		if (paddlePos.x + pSize.x >= mWidth)
			player.setPosition(sf::Vector2f(mWidth - pSize.x - 1, paddlePos.y));
		if (paddlePos.x <= 0)
			player.setPosition(sf::Vector2f(1, paddlePos.y));
	}
	else
	{
		player.setRightState(false);
		player.setLeftState(false);
	}
	if (paddlePos.x + pSize.x > mWidth || paddlePos.x < 0)
	{
		player.setRightState(false);
		player.setLeftState(false);
	}
}

void BrickGame::brickProcess()
{
	for (int i = 0; i < wallHeight; i++)
	{
		for (int j = 0; j < wallWidth; j++)
		{
			if (Wall[i * wallWidth + j] > 0 && Wall[i * wallWidth + j]->isAlive())
			{
				Wall[i * wallWidth + j]->checkCollision(newBall); //Kiểm tra va chạm của từng viên gạch với bóng
				Wall[i * wallWidth + j]->paddleAction(player); //Hiệu ứng của gạch với người chơi
				if (Wall[i * wallWidth + j]->getHP() == 0) //Nếu gạch bị phá huỷ thì xoá gạch và thay thế bằng đối tượng gạch mặc định
				{
					sf::Vector2f tmp(Wall[i * wallWidth + j]->getPosition());
					delete Wall[i * wallWidth + j];
					Wall[i * wallWidth + j] = new Brick;
					Wall[i * wallWidth + j]->setPosition(tmp);
				}
				/*if (Wall[i * wallWidth + j]->getHP() == 0)
				{
					player.setScore(player.getScore() + Wall[i * wallWidth + j]->getScore());
				}*/
			}
		}
	}
}

int* BrickGame::exportBrickMap()
{
	int* map = new int[wallWidth * wallHeight];
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			map[i * wallWidth + j] = Wall[i * wallWidth + j]->getType();
		}
	return map;
}

void BrickGame::saveGame(const std::string& path)
{
	std::ofstream file;
	file.open(path);
	if (!file.is_open()) return;
	int* map = exportBrickMap(); int mapSize = wallWidth * wallHeight;
	sf::Vector2f pos(newBall.getPosition()), dir(newBall.getDirection());
	float speed = newBall.getSpeed();
	file << life << "," << player.getScore() << "," << pos.x << "," << pos.y << "," << dir.x << "," << dir.y << "," << speed;
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			file << "," << map[i * wallWidth + j];
		}
	delete map;
	file.close();
}

void BrickGame::loadGame(const std::string& path)
{
	std::ifstream file;
	file.open(path);
	if (!file.is_open()) return;
	sf::Vector2f pos, dir;
	float speed;
	std::string tmp;
	char delim = ',';
	std::getline(file, tmp, delim);
	life = std::stoi(tmp);
	std::getline(file, tmp, delim);
	player.setScore(std::stoi(tmp));
	std::getline(file, tmp, delim);
	pos.x = std::stof(tmp);
	std::getline(file, tmp, delim);
	pos.y = std::stof(tmp);
	std::getline(file, tmp, delim);
	dir.x = std::stof(tmp);
	std::getline(file, tmp, delim);
	dir.y = std::stof(tmp);
	std::getline(file, tmp, delim);
	speed = std::stof(tmp);
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			std::getline(file, tmp, delim);
			brickMap[i * wallWidth + j] = std::stoi(tmp);
		}
	file.close();
	newBall.setPosition(pos);
	newBall.setDirection(dir);
	newBall.setSpeed(speed);
}

void BrickGame::readPossibility(const std::string& path, std::vector<int>& possibility)
{
	ifstream file(path);
	if (!file.is_open()) return;
	possibility.clear();
	std::string tmp;
	char delim = ',';
	std::getline(file, tmp, delim);
	possibility.push_back(std::stoi(tmp));
	std::getline(file, tmp, delim);
	possibility.push_back(std::stoi(tmp));
	std::getline(file, tmp, delim);
	possibility.push_back(std::stoi(tmp));
	std::getline(file, tmp, delim);
	possibility.push_back(std::stoi(tmp));
	std::getline(file, tmp, delim);
	possibility.push_back(std::stoi(tmp));
	std::getline(file, tmp, delim);
	possibility.push_back(std::stoi(tmp));
	file.close();
}

void BrickGame::loadDifficulty()
{
	std::string path = "Difficulty\\";
	switch (mode)
	{
	case EASY:
		path += "EASY.txt";
		break;
	case NORMAL:
		path += "NORMAL.txt";
		break;
	case HARD:
		path += "HARD.txt";
		break;
	default:
		break;
	}
	readPossibility(path, possibility);
}

void BrickGame::loadSaveFile(const std::string& path)
{
	std::string dir = path + "\\savegame", ext = ".txt";
	for (int i = 0; i < nSave; i++)
	{
		if (save[i] != NULL)
			delete save[i];
		save[i] = new Save;
		if (!save[i]->loadFromFile(dir + std::to_string(i + 1) + ext))
		{
			delete save[i];
			save[i] = NULL;
			svMenu.text[i].setString("Empty");
		}
		else
		{
			svMenu.text[i].setString(save[i]->timeSave);
		}
	}
}

void BrickGame::applySave(Save& save)
{
	newBall.setPosition(save.ballPos);
	newBall.setDirection(save.ballDir);
	life = save.life;
	player.setScore(save.score);
	newBall.setSpeed(save.speed);
	mode = save.mode;
	for (int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			brickMap[i * wallWidth + j] = save.brickMap[i * wallWidth + j];
		}
}

void BrickGame::createSave(int index)
{
	if (save[index] != NULL)
		delete save[index];
	int* map = exportBrickMap();
	save[index] = new Save(mode, life, player.getScore(), newBall.getSpeed(), newBall.getPosition(), newBall.getDirection(), map);
	svMenu.text[index].setString(save[index]->timeSave);
	save[index]->saveToFile("Save\\savegame" + std::to_string(index + 1) + ".txt");
}




