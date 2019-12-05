#include "EndGameMenu.h"

EndGameMenu::EndGameMenu(int result)
{
	if (result == 1)
	{
		sf::Font font;
		font.loadFromFile("resource\\Retro Gaming.ttf");

		resultText.setFont(font);
		resultText.setCharacterSize(80);
		resultText.setFillColor(sf::Color::Red);
		resultText.setString("You win");
		resultText.setPosition(mWidth/2 - 280, mHeight/2 - 50);

		leftBox.setSize(sf::Vector2f(200, 50));
		leftBox.setFillColor(sf::Color(128,128,128));
		leftBox.setOutlineThickness(2);
		leftBox.setOutlineColor(sf::Color::White);
		leftBox.setPosition(sf::Vector2f(0, mHeight - 50));

		leftText.setFont(font);
		leftText.setCharacterSize(25);
		leftText.setString("Main Menu");
		leftText.setFillColor(sf::Color::White);
		leftText.setPosition(sf::Vector2f(leftBox.getPosition().x + 50, leftBox.getPosition().y + 8));

		rightBox = leftBox;
		rightBox.setPosition(sf::Vector2f(mWidth - 200, mHeight - 50));

		rightText = leftText;
		rightText.setString("Leader Board");
		rightText.setPosition(sf::Vector2f(rightBox.getPosition().x + 50, rightBox.getPosition().y + 8));
	}
}

void EndGameMenu::setState(int state)
{
	mState = state;
}

int EndGameMenu::getState()
{
	return mState;
}

void EndGameMenu::updateMenu()
{
	switch (mState)
	{
		case 1:
		{
			leftBox.setFillColor(sf::Color::White);
			leftBox.setOutlineColor(sf::Color(128,128,128));
			leftText.setFillColor(sf::Color::Black);

			rightBox.setFillColor(sf::Color(128,128,128));
			rightBox.setOutlineColor(sf::Color::White);
			rightText.setFillColor(sf::Color::White);
		}
		case 2:
		{
			leftBox.setFillColor(sf::Color(128, 128, 128));
			leftBox.setOutlineColor(sf::Color::White);
			leftText.setFillColor(sf::Color::White);

			rightBox.setFillColor(sf::Color::White);
			rightBox.setOutlineColor(sf::Color(128, 128, 128));
			rightText.setFillColor(sf::Color::Black);
		}
	}
}

void EndGameMenu::changeState(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left)
	{
		if (mState == 1)
			mState = 2;
		else mState--;
	}
	if (key == sf::Keyboard::Right)
	{
		if (mState == 2)
		{
			mState = 1;
		}
		else mState++;
	}
}
