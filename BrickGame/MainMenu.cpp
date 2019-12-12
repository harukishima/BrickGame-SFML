#include "MainMenu.h"

MainMenu::MainMenu()
{
	font.loadFromFile("resource\\Retro Gaming.ttf");

	title.setFont(font);
	title.setCharacterSize(55);
	title.setString("Brick Game");
	title.setFillColor(sf::Color::Blue);
	title.setPosition(sf::Vector2f(mWidth / 2 - 150, mHeight / 2 - 240));


	firstText.setFont(font);
	firstText.setCharacterSize(25);
	firstText.setString("Continue");
	firstText.setFillColor(sf::Color::Red);
	firstText.setPosition(sf::Vector2f(mWidth / 2 - 100, mHeight / 2 - 125));

	//add firstBox & firstText while having data game 

	secondText = firstText;
	secondText.setString("Start game");
	secondText.setPosition(sf::Vector2f(firstText.getPosition().x, firstText.getPosition().y + 75));

	thirdText = firstText;
	thirdText.setString("Difficulty");
	thirdText.setPosition(sf::Vector2f(secondText.getPosition().x, secondText.getPosition().y + 75));
	fourthText = firstText;
	fourthText.setString("Demo");
	fourthText.setPosition(sf::Vector2f(thirdText.getPosition().x, thirdText.getPosition().y + 75));
	
	fifthText = firstText;
	fifthText.setString("Score Board");
	fifthText.setPosition(sf::Vector2f(fourthText.getPosition().x, fourthText.getPosition().y +75));

	sixthText = firstText;
	sixthText.setString("Exit");
	sixthText.setPosition(sf::Vector2f(fifthText.getPosition().x, fifthText.getPosition().y + 75));
}

int MainMenu::getState()
{
	return mState;
}
 
void MainMenu::updateMenu()
{
	switch (mState)
	{
		case 1:
		{
			firstText.setFillColor(sf::Color::Blue);
			secondText.setFillColor(sf::Color::Red);
			thirdText.setFillColor(sf::Color::Red);
			fourthText.setFillColor(sf::Color::Red);
			fifthText.setFillColor(sf::Color::Red);
			sixthText.setFillColor(sf::Color::Red);
			break;
		}
		case 2:
		{
			firstText.setFillColor(sf::Color::Red);
			secondText.setFillColor(sf::Color::Blue);
			thirdText.setFillColor(sf::Color::Red);
			fourthText.setFillColor(sf::Color::Red);
			fifthText.setFillColor(sf::Color::Red);
			sixthText.setFillColor(sf::Color::Red);
			break;
		}
		case 3:
		{
			firstText.setFillColor(sf::Color::Red);
			secondText.setFillColor(sf::Color::Red);
			thirdText.setFillColor(sf::Color::Blue);
			fourthText.setFillColor(sf::Color::Red);
			fifthText.setFillColor(sf::Color::Red);
			sixthText.setFillColor(sf::Color::Red);
			break;
		}
		case 4:
		{
			firstText.setFillColor(sf::Color::Red);
			secondText.setFillColor(sf::Color::Red);
			thirdText.setFillColor(sf::Color::Red);
			fourthText.setFillColor(sf::Color::Blue);
			fifthText.setFillColor(sf::Color::Red);
			sixthText.setFillColor(sf::Color::Red);
			break;
		}
		case 5:
		{
			firstText.setFillColor(sf::Color::Red);
			secondText.setFillColor(sf::Color::Red);
			thirdText.setFillColor(sf::Color::Red);
			fourthText.setFillColor(sf::Color::Red);
			fifthText.setFillColor(sf::Color::Blue);
			sixthText.setFillColor(sf::Color::Red);
			break;
		}
		case 6:
		{
			firstText.setFillColor(sf::Color::Red);
			secondText.setFillColor(sf::Color::Red);
			thirdText.setFillColor(sf::Color::Red);
			fourthText.setFillColor(sf::Color::Red);
			fifthText.setFillColor(sf::Color::Red);
			sixthText.setFillColor(sf::Color::Blue);
			break;
		}
	}

}

void MainMenu::changeState(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up)
	{
		if (mState == 1)
			mState = 6;
		else mState--;
	}
	if (key == sf::Keyboard::Down)
	{
		if (mState == 6)
		{
			mState = 1;
		}
		else mState++;
	}
}

