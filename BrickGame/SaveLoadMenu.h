#ifndef __SAVELOADMENU_H__
#define __SAVELOADMENU_H__



#include "Menu.h"
#include "Global.h"
class SaveLoadMenu :
	public Menu
{
private:
	int mState = 1;
	sf::Font font;
public:
	sf::Text title;
	sf::Text text[7];


	SaveLoadMenu();
	int getState();
	virtual void updateMenu();
	virtual void changeState(sf::Keyboard::Key key);



};







#endif // !__SAVELOADMENU_H__