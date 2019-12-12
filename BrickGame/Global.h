#ifndef __GLOBAL_H__
#define __GLOBAL_H__

const unsigned int mWidth = 600; //Chiều rộng cửa sổ
const unsigned int mHeight = 800; //Chiều cao cửa sổ
const unsigned int wallWidth = 10; //Số gạch theo chiều ngang 10
const unsigned int wallHeight = 8; //Số gạch theo chiều cao 8
const float WinHeightRatio = 0.3f; //Tỉ lệ giữa gạch và chiều cao cửa sổ
const float WinWidthRatio = 1.f; //Tỉ lệ giữa gạch và chiều rộng cửa sổ
const float board = 75.f;
const float maxBallSpeed = 750;
const int defaultLife = 5;


enum Difficulty
{
	EASY,
	NORMAL,
	HARD
};

#endif // !__GLOBAL_H__