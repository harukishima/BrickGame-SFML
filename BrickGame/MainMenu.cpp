#include "MainMenu.h"

MainMenu::MainMenu()
{
	sf::Font font;
	font.loadFromFile("resource\\Retro Gaming.ttf");

	firstBox.setSize(sf::Vector2f(200, 50));
	firstBox.setFillColor(sf::Color::Red);
	firstBox.setOutlineThickness(2);
	firstBox.setOutlineColor(sf::Color::White);
	firstBox.setPosition(sf::Vector2f(mWidth / 2 - 100, mHeight / 2 + 200));

	firstText.setFont(font);
	firstText.setCharacterSize(25);
	firstText.setString("Continue");
	firstText.setFillColor(sf::Color::Yellow);
	firstText.setPosition(sf::Vector2f(firstBox.getPosition().x + 50, firstBox.getPosition().y + 8));

	//add firstBox & firstText while having data game 

	secondBox = firstBox;
	secondBox.setPosition(sf::Vector2f(firstBox.getPosition().x, firstBox.getPosition().y - 100));
	secondText = firstText;
	secondText.setString("Single");
	secondText.setPosition(sf::Vector2f(secondBox.getPosition().x + 50, secondBox.getPosition().y + 8));

	thirdBox = firstBox;
	thirdBox.setPosition(sf::Vector2f(secondBox.getPosition().x, secondBox.getPosition().y - 100));
	thirdText = firstText;
	thirdText.setString("Multi");
	thirdText.setPosition(sf::Vector2f(thirdBox.getPosition().x + 50, thirdBox.getPosition().y + 8));

	fourthBox = firstBox;
	fourthBox.setPosition(sf::Vector2f(thirdBox.getPosition().x, thirdBox.getPosition().y - 100));
	fourthText = firstText;
	fourthText.setString("Demo");
	fourthText.setPosition(sf::Vector2f(fourthBox.getPosition().x + 50, fourthBox.getPosition().y + 8));

	fifthBox = firstBox;
	fifthBox.setPosition(sf::Vector2f(fourthBox.getPosition().x, fourthBox.getPosition().y - 100));
	fifthText = firstText;
	fifthText.setString("Leader Board");
	fifthText.setPosition(sf::Vector2f(fifthBox.getPosition().x + 50, fifthBox.getPosition().y + 8));

	sixthBox = firstBox;
	sixthBox.setPosition(sf::Vector2f(fifthBox.getPosition().x, fifthBox.getPosition().y - 100));
	sixthText = firstText;
	sixthText.setString("Exit");
	sixthText.setPosition(sf::Vector2f(sixthBox.getPosition().x + 50, sixthBox.getPosition().y + 8));
}
 
void MainMenu::updateMenu()
{
	switch (mState)
	{
		case 1:
		{
			firstBox.setOutlineColor(sf::Color::Green);
			secondBox.setOutlineColor(sf::Color::White);
			thirdBox.setOutlineColor(sf::Color::White);
			fourthBox.setOutlineColor(sf::Color::White);
			fifthBox.setOutlineColor(sf::Color::White);
			sixthBox.setOutlineColor(sf::Color::White);
		}
		case 2:
		{
			firstBox.setOutlineColor(sf::Color::White);
			secondBox.setOutlineColor(sf::Color::Green);
			thirdBox.setOutlineColor(sf::Color::White);
			fourthBox.setOutlineColor(sf::Color::White);
			fifthBox.setOutlineColor(sf::Color::White);
			sixthBox.setOutlineColor(sf::Color::White);
		}
		case 3:
		{
			firstBox.setOutlineColor(sf::Color::White);
			secondBox.setOutlineColor(sf::Color::White);
			thirdBox.setOutlineColor(sf::Color::Green);
			fourthBox.setOutlineColor(sf::Color::White);
			fifthBox.setOutlineColor(sf::Color::White);
			sixthBox.setOutlineColor(sf::Color::White);
		}
		case 4:
		{
			firstBox.setOutlineColor(sf::Color::White);
			secondBox.setOutlineColor(sf::Color::White);
			thirdBox.setOutlineColor(sf::Color::White);
			fourthBox.setOutlineColor(sf::Color::Green);
			fifthBox.setOutlineColor(sf::Color::White);
			sixthBox.setOutlineColor(sf::Color::White);
		}
		case 5:
		{
			firstBox.setOutlineColor(sf::Color::White);
			secondBox.setOutlineColor(sf::Color::White);
			thirdBox.setOutlineColor(sf::Color::White);
			fourthBox.setOutlineColor(sf::Color::White);
			fifthBox.setOutlineColor(sf::Color::Green);
			sixthBox.setOutlineColor(sf::Color::White);
		}
		case 6:
		{
			firstBox.setOutlineColor(sf::Color::White);
			secondBox.setOutlineColor(sf::Color::White);
			thirdBox.setOutlineColor(sf::Color::White);
			fourthBox.setOutlineColor(sf::Color::White);
			fifthBox.setOutlineColor(sf::Color::White);
			sixthBox.setOutlineColor(sf::Color::Green);
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

