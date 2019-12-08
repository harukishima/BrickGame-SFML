#ifndef __HBRICK_H__
#define __HBRICK_H__


#include "Brick.h"
class HBrick :
	public Brick
{
public:
	HBrick();
	virtual ~HBrick() = default;
	virtual int getType() { return 3; }

};




#endif // !__HBRICK_H__



