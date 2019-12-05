#ifndef __PAUSEMENU_H__
#define __PAUSEMENU_H__

#include "Menu.h"
#include "Global.h"
#include<SFML\Graphics.hpp>

class EndGameMenu :public Menu
{
private:
	int mState = 1;
public:
	sf::Text leftText, rightText, resultText;
	sf::RectangleShape leftBox, rightBox;

	EndGameMenu(int result);
	virtual ~EndGameMenu() = default;

	void setState(int state);
	int getState();
	virtual void updateMenu();
	virtual void changeState(sf::Keyboard::Key key);
};


#endif
