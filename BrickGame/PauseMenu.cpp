#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	font.loadFromFile("resource\\Retro Gaming.ttf");

	upperText.setFont(font);
	upperText.setCharacterSize(25);
	upperText.setString("Continue");
	upperText.setFillColor(sf::Color::Red);
	upperText.setPosition(sf::Vector2f(mWidth/2 - 100, mHeight/2 - 125));

	middleText = upperText;
	middleText.setString("Save");
	middleText.setPosition(sf::Vector2f(upperText.getPosition().x, upperText.getPosition().y + 50));

	underText = upperText;
	underText.setString("Main menu");
	underText.setPosition(sf::Vector2f(middleText.getPosition().x, middleText.getPosition().y + 50));
}

void PauseMenu::setState(int state)
{
	mState = state;
}

int PauseMenu::getState()
{
	return mState;
}

void PauseMenu::updateMenu()
{
	switch (mState)
	{
		case 1:
		{
			upperText.setFillColor(sf::Color::Blue);
			middleText.setFillColor(sf::Color::Red);
			underText.setFillColor(sf::Color::Red);
			break;
		}
		case 2:		  
		{
			upperText.setFillColor(sf::Color::Red);
			middleText.setFillColor(sf::Color::Blue);
			underText.setFillColor(sf::Color::Red);
			break;
		}
		case 3:
		{
			upperText.setFillColor(sf::Color::Red);
			middleText.setFillColor(sf::Color::Red);
			underText.setFillColor(sf::Color::Blue);
			break;
		}
	}
}

void PauseMenu::changeState(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up)
	{
		if (mState == 1)
			mState = 3;
		else mState--;
	}
	if (key == sf::Keyboard::Down)
	{
		if (mState == 3)
		{
			mState = 1;
		}
		else mState++;
	}
}


