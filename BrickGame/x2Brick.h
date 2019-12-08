#ifndef __X2BRICK_H__
#define __X2BRICK_H__





#include "Brick.h"
class x2Brick :
	public Brick
{
public:
	x2Brick();
	virtual ~x2Brick() = default;
	virtual int getType() { return 4; }
	void paddleAction(Paddle&);
};


#endif // !__X2BRICK_H__