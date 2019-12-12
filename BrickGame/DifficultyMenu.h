#ifndef __DIFFICULTYMENU_H__
#define __DIFFICULTYMENU_H__



#include "Menu.h"
#include "Global.h"

class DifficultyMenu :
	public Menu
{
private:
	int mState = 1;
	sf::Font font;
public:
	sf::Text firstText, secondText, thirdText, title, curDiff;

	DifficultyMenu();
	virtual ~DifficultyMenu() = default;

	int getState() { return mState; };
	virtual void updateMenu();
	virtual void changeState(sf::Keyboard::Key key);
};







#endif // !__DIFFICULTYMENU_H__