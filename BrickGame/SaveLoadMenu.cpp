#include "SaveLoadMenu.h"

SaveLoadMenu::SaveLoadMenu()
{
	font.loadFromFile("resource\\Retro Gaming.ttf");

	title.setFont(font);
	title.setCharacterSize(55);
	title.setString("Save game");
	title.setFillColor(sf::Color::Blue);
	title.setPosition(sf::Vector2f(mWidth / 2 - 150, mHeight / 2 - 240));


	text[0].setFont(font);
	text[0].setCharacterSize(25);
	text[0].setString("Empty");
	text[0].setFillColor(sf::Color::Red);
	text[0].setPosition(sf::Vector2f(mWidth / 2 - 125, mHeight / 2 - 125));


	text[1] = text[0];
	text[1].setString("Empty");
	text[1].setPosition(sf::Vector2f(text[0].getPosition().x, text[0].getPosition().y + 50));

	text[2] = text[0];
	text[2].setString("Empty");
	text[2].setPosition(sf::Vector2f(text[1].getPosition().x, text[1].getPosition().y + 50));

	text[3] = text[0];
	text[3].setString("Empty");
	text[3].setPosition(sf::Vector2f(text[2].getPosition().x, text[2].getPosition().y + 50));

	text[4] = text[0];
	text[4].setString("Empty");
	text[4].setPosition(sf::Vector2f(text[3].getPosition().x, text[3].getPosition().y + 50));

	text[5] = text[0];
	text[5].setString("Empty");
	text[5].setPosition(sf::Vector2f(text[4].getPosition().x, text[4].getPosition().y + 50));

	text[6] = text[0];
	text[6].setString("Empty");
	text[6].setPosition(sf::Vector2f(text[5].getPosition().x, text[5].getPosition().y + 50));
}

int SaveLoadMenu::getState()
{
	return mState;
}

void SaveLoadMenu::updateMenu()
{
	switch (mState)
	{
	case 1:
	{
		text[0].setFillColor(sf::Color::Blue);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);
		break;
	}
	case 2:
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::Blue);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);
		break;
	}
	case 3:
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Blue);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);
		break;
	}
	case 4:
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::Blue);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);
		break;
	}
	case 5:
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Blue);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);
		break;
	}
	case 6:
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::Blue);
		text[6].setFillColor(sf::Color::Red);
		break;
	}
	case 7:
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Blue);
		break;
	}
	}
}

void SaveLoadMenu::changeState(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up)
	{
		if (mState == 1)
			mState = 7;
		else mState--;
	}
	if (key == sf::Keyboard::Down)
	{
		if (mState == 7)
		{
			mState = 1;
		}
		else mState++;
	}
}
