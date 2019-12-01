#ifndef __NBRICK_H__
#define __NBRICK_H__



#include "Brick.h"
class NBrick :
	public Brick
{
public:
	NBrick();
	virtual ~NBrick() = default;
	virtual int getType() { return 1; }
};




#endif // !__GLOBAL_H__