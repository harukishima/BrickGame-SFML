#include "BrickGame.h"
#include "Global.h"

BrickGame::BrickGame() :
	mWindow(sf::VideoMode(mWidth, mHeight), "Brick Game")
{
	randomizeBrickMap();
	createWall();
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
		/*case sf::Event::KeyPressed:
			handleInput(ev.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handleInput(ev.key.code, false);
			break;*/
		}
	}
}

void BrickGame::update(sf::Time TimePerFrame)
{
	checkWallCollision();
	updateBall(TimePerFrame);
	for (int i = 0; i < wallHeight; i++)
	{
		for (int j = 0; j < wallWidth; j++)
		{
			if (Wall[i * wallWidth + j] > 0 && Wall[i * wallWidth + j]->isAlive())
				Wall[i * wallWidth + j]->checkCollision(newBall);
		}
	}
}

void BrickGame::render()
{
	mWindow.clear();
	for (int i = 0; i < wallHeight; i++)
	{
		for (int j = 0; j < wallWidth; j++)
		{
			if (Wall[i * wallWidth + j] > 0 && Wall[i * wallWidth + j]->isAlive())
				mWindow.draw(*Wall[i * wallWidth + j]);
		}
	}
	mWindow.draw(newBall);
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
			Wall[i * wallWidth + j]->setPosition(sf::Vector2f(tmp.x * j, tmp.y * i));
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
	if (pos.x - newBall.getRadius() <= 0)
	{
		dir.x = -dir.x;
		pos.x = newBall.getRadius();
	}
	if (pos.y - newBall.getRadius() <= 0)
	{
		dir.y = -dir.y;
		pos.y = newBall.getRadius();
	}
	if (pos.x + newBall.getRadius() >= mWidth)
	{
		dir.x = -dir.x;
		pos.x = mWidth - newBall.getRadius();
	}
	if (pos.y + newBall.getRadius() >= mHeight) //For testing purpose
	{
		dir.y = -dir.y;
		pos.y = mHeight - newBall.getRadius();
	}
	newBall.setDirection(dir);
	newBall.setPosition(pos);
}

void BrickGame::updateBall(sf::Time TimePerFrame)
{
	sf::Vector2f movement;
	movement = newBall.getDirection() * newBall.getSpeed() * TimePerFrame.asSeconds();
	newBall.move(movement);
}
