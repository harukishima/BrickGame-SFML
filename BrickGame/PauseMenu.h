#ifndef __PAUSEMENU_H__
#define __PAUSEMENU_H__

#include "Menu.h"
#include "Global.h"
#include<SFML\Graphics.hpp>

class PauseMenu :public Menu
{
private:
	int mState = 1;
public:
	sf::Text upperText, underText;
	sf::RectangleShape upperBox, underBox;

	PauseMenu();
	virtual ~PauseMenu() = default;

	void setState(int state);
	int getState();
	virtual void updateMenu();
	virtual void changeState(sf::Keyboard::Key key);
};


#endif

