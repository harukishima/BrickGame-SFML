#include "DifficultyMenu.h"

DifficultyMenu::DifficultyMenu()
{
	font.loadFromFile("resource\\Retro Gaming.ttf");

	title.setFont(font);
	title.setCharacterSize(55);
	title.setString("Difficulty");
	title.setFillColor(sf::Color::Blue);
	title.setPosition(sf::Vector2f(mWidth / 2 - 150, mHeight / 2 - 240));

	curDiff.setFont(font);
	curDiff.setCharacterSize(25);
	curDiff.setString("Current mode: ");
	curDiff.setFillColor(sf::Color::White);
	curDiff.setPosition(sf::Vector2f(mWidth / 2 - 150, mHeight / 2 - 125));


	firstText.setFont(font);
	firstText.setCharacterSize(25);
	firstText.setString("EASY");
	firstText.setFillColor(sf::Color::Red);
	firstText.setPosition(sf::Vector2f(mWidth / 2 - 100, mHeight / 2));


	secondText = firstText;
	secondText.setString("NORMAL");
	secondText.setPosition(sf::Vector2f(firstText.getPosition().x, firstText.getPosition().y + 75));

	thirdText = firstText;
	thirdText.setString("HARD");
	thirdText.setPosition(sf::Vector2f(secondText.getPosition().x, secondText.getPosition().y + 75));
}

void DifficultyMenu::updateMenu()
{
	switch (mState)
	{
	case 1:
	{
		firstText.setFillColor(sf::Color::Blue);
		secondText.setFillColor(sf::Color::Red);
		thirdText.setFillColor(sf::Color::Red);
		break;
	}
	case 2:
	{
		firstText.setFillColor(sf::Color::Red);
		secondText.setFillColor(sf::Color::Blue);
		thirdText.setFillColor(sf::Color::Red);
		break;
	}
	case 3:
	{
		firstText.setFillColor(sf::Color::Red);
		secondText.setFillColor(sf::Color::Red);
		thirdText.setFillColor(sf::Color::Blue);
		break;
	}
	}
	
}

void DifficultyMenu::changeState(sf::Keyboard::Key key)
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
