#ifndef __MENU_H__
#define __MENU_H__


#include<SFML\Graphics.hpp>

class Menu
{
public:
	Menu();
	int mState = 0;
	virtual ~Menu() = default;
	virtual void updateMenu() = 0;
	virtual void changeState(sf::Keyboard::Key key) = 0;
};

#endif

