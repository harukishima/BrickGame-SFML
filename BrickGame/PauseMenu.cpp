#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	sf::Font font;
	font.loadFromFile("resource\\Retro Gaming.ttf");

	upperBox.setSize(sf::Vector2f(200, 50));
	upperBox.setFillColor(sf::Color::Red);
	upperBox.setOutlineThickness(2);
	upperBox.setOutlineColor(sf::Color::White);
	upperBox.setPosition(sf::Vector2f(mWidth / 2 - 100, mHeight / 2 - 25));

	upperText.setFont(font);
	upperText.setCharacterSize(25);
	upperText.setString("Continue");
	upperText.setFillColor(sf::Color::Blue);
	upperText.setPosition(sf::Vector2f(upperBox.getPosition().x + 50, upperBox.getPosition().y + 8));

	underBox = upperBox;
	underBox.setPosition(sf::Vector2f(mWidth / 2 - 100, mHeight / 2 - 150));

	underText = upperText;
	underText.setString("Main menu");
	underText.setPosition(sf::Vector2f(underBox.getPosition().x + 35, underBox.getPosition().y + 8));
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
			upperBox.setOutlineColor(sf::Color::Blue);
			underBox.setOutlineColor(sf::Color::White);
		}
		case 2:		  
		{
			underBox.setOutlineColor(sf::Color::Blue);
			upperBox.setOutlineColor(sf::Color::White);
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


