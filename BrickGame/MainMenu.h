#ifndef __MAINMENU_H
#define __MAINMENU_H

#include "Menu.h"
#include "Global.h"
#include<SFML\Graphics.hpp>

class MainMenu:public Menu
{
private:
	int mState = 1;
public:
	sf::Text firstText, secondText, thirdText, fourthText, fifthText, sixthText;
	sf::RectangleShape firstBox, secondBox, thirdBox, fourthBox, fifthBox, sixthBox;

	MainMenu();

	virtual void updateMenu();
	virtual void changeState(sf::Keyboard::Key key);



};

#endif

