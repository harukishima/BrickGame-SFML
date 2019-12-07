#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	sf::Font font;
	font.loadFromFile("resource\\Retro Gaming.ttf");

	upperText.setFont(font);
	upperText.setCharacterSize(25);
	upperText.setString("Continue");
	upperText.setFillColor(sf::Color::Red);
	upperText.setPosition(sf::Vector2f(mWidth/2 - 100, mHeight/2 - 125));

	underText = upperText;
	underText.setString("Main menu");
	underText.setPosition(sf::Vector2f(upperText.getPosition().x, upperText.getPosition().y + 50));
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
			upperText.setFillColor(sf::Color::Yellow);
			underText.setFillColor(sf::Color::Red);
		}
		case 2:		  
		{
			upperText.setFillColor(sf::Color::Red);
			underText.setFillColor(sf::Color::Yellow);
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


