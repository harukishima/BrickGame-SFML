#ifndef __METALBRICK_H__
#define __METALBRICK_H__


#include "Brick.h"
class MetalBrick :
	public Brick
{
public:
	MetalBrick();
	virtual ~MetalBrick() = default;
	virtual int getType() { return 5; }
};






#endif // !__METALBRICK_H__