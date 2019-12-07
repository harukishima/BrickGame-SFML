#include "BrickGame.h"
#include "Global.h"

BrickGame::BrickGame() :
	mWindow(sf::VideoMode(mWidth, mHeight), "Brick Game")
{
	newBall.defaultState();
	font.loadFromFile("resource\\Retro Gaming.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setPosition(sf::Vector2f(50, 15));
	lifeText.setFont(font);
	lifeText.setCharacterSize(30);
	lifeText.setPosition(sf::Vector2f(400, 15));
	randomizeBrickMap(); //Tạo ngẫu nhiên tilemap
	createWall(); //Xây dựng tường gạch
	
}

BrickGame::~BrickGame()
{
	destroyWall();
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
		if (isPlaying && key == sf::Keyboard::Left)
		{
			player.setLeftState(isPressed);
		}
		if (isPlaying && key == sf::Keyboard::Right)
		{
			player.setRightState(isPressed);
		}
		if (isPlaying && key == sf::Keyboard::Escape)
		{
			isPause = true;
			isPlaying = false;
		}

		if (isPressed)
		{
			if (isEnd)
			{
				endMenu.changeState(key);
				if (endMenu.getState() == 1 && key == sf::Keyboard::Enter)
				{
					isMainMenu = true;
					isPlaying = false;
					isEnd = false;
				}
				else if (endMenu.getState() == 2 && key == sf::Keyboard::Enter)
				{
					isPlaying = false;
					isEnd = false;
					// enter scoreboard
				}
			}
			if (isMainMenu)
			{
				mainMenu.changeState(key);
				if (key == sf::Keyboard::Enter)
				{
					switch (mainMenu.getState())
					{
					case 1:
					{
						if (!isEnd && !isPlaying)
						{
							isPlaying = true;
							break;
						}
					}
					case 2:
					{
						isMainMenu = false;
						isPlaying = true;
						// endless mode
						break;
					}
					case 3:
					{
						isMainMenu = false;
						isPlaying = true;
						// the left mode
						break;
					}
					case 4:
					{
						isMainMenu = false;
						// demo
						break;
					}
					case 5:
					{
						isMainMenu = false;
						isPlaying = true;
						// enter scoreboard
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
			if (isPause)
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
							isPlaying = false;
							isMainMenu = true;
							break;
						}
					}
				}
			}
		}
}

void BrickGame::update(sf::Time TimePerFrame)
{
	checkWallCollision();
	updateBall(TimePerFrame);
	player.processMove();
	player.checkCollision(newBall);
	updatePaddle(TimePerFrame);
	player.animate();
	scoreText.setString("Score: " + std::to_string(player.getScore()));
	lifeText.setString("Life: " + std::to_string(life));
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
		mWindow.draw(pauseMenu.underText);
	}
	else if (isEnd)
	{
		mWindow.draw(endMenu.resultText);
		mWindow.draw(endMenu.leftText);
		mWindow.draw(endMenu.rightText);
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
			delete Wall[i * wallHeight + j];
		}
}

void BrickGame::randomizeBrickMap()
{
	srand((int)time(0));
	for(int i = 0; i < wallHeight; i++)
		for (int j = 0; j < wallWidth; j++)
		{
			brickMap[i * wallHeight + j] = rand() % 4;
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

int BrickGame::checkProcessCondition()
{
	if (life <= 0)
	{
		return -1; // lose
	}
	else return 0; // nothing happens
}


