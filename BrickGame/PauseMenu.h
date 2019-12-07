#ifndef __PAUSEMENU_H
#define __PAUSEMENU_H

#include "Menu.h"
#include "Global.h"
#include<SFML\Graphics.hpp>

class PauseMenu :public Menu
{
private:
	int mState = 1;
public:
	sf::Text upperText, underText;
	sf::Font font;

	PauseMenu();
	virtual ~PauseMenu() = default;

	void setState(int state);
	int getState();
	virtual void updateMenu();
	virtual void changeState(sf::Keyboard::Key key);
};


#endif

