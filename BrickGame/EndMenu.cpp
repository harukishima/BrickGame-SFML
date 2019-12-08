#include "EndMenu.h"

EndMenu::EndMenu()
{
		font.loadFromFile("resource\\Retro Gaming.ttf");

		resultText.setFont(font);
		resultText.setCharacterSize(60);
		resultText.setFillColor(sf::Color::Red);
		resultText.setString("You lose");
		resultText.setPosition(mWidth / 2 - 150, mHeight / 2 - 50);

		leftText.setFont(font);
		leftText.setCharacterSize(25);
		leftText.setString("Main Menu");
		leftText.setFillColor(sf::Color::White);
		leftText.setPosition(sf::Vector2f(0, mHeight - 85));


		rightText = leftText;
		rightText.setString("Score Board");
		rightText.setPosition(sf::Vector2f(mWidth - 200, mHeight - 85));

	// another result will add 
}

void EndMenu::setState(int state)
{
	mState = state;
}

int EndMenu::getState()
{
	return mState;
}

void EndMenu::updateMenu()
{
	switch (mState)
	{
	case 1:
	{
		leftBox.setFillColor(sf::Color::White);
		leftBox.setOutlineColor(sf::Color(128, 128, 128));
		leftText.setFillColor(sf::Color::Red);

		rightBox.setFillColor(sf::Color(128, 128, 128));
		rightBox.setOutlineColor(sf::Color::White);
		rightText.setFillColor(sf::Color::White);
		break;
	}
	case 2:
	{
		leftBox.setFillColor(sf::Color(128, 128, 128));
		leftBox.setOutlineColor(sf::Color::White);
		leftText.setFillColor(sf::Color::White);

		rightBox.setFillColor(sf::Color::White);
		rightBox.setOutlineColor(sf::Color(128, 128, 128));
		rightText.setFillColor(sf::Color::Red);
		break;
	}
	}
}

void EndMenu::changeState(sf::Keyboard::Key key)
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

void EndMenu::clearEndlessMess()
{
	font.loadFromFile("resource\\Retro Gaming.ttf");

	nextMess.setFont(font);
	nextMess.setCharacterSize(60);
	nextMess.setFillColor(sf::Color::Red);
	nextMess.setString("Clear, press Enter to continue challenging");
	nextMess.setPosition(mWidth / 2 - 150, mHeight / 2 - 50);
}
