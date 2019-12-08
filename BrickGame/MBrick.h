#ifndef __MBRICK_H__
#define __MBRICK_H__



#include "Brick.h"
class MBrick :
	public Brick
{
public:
	MBrick();
	virtual ~MBrick() = default;
	virtual int getType() { return 2; }

};




#endif // !__GLOBAL_H__
