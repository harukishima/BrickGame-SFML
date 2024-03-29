#ifndef __MOVEABLEOBJECT_H__
#define __MOVEABLEOBJECT_H__

#include<SFML\Graphics.hpp>


class MoveableObject
{
protected:
	float mSpeed; //Tốc độ của vật
	sf::Vector2f mDirection; //Vector hướng
public:
	MoveableObject();
	virtual ~MoveableObject() = default;
	virtual void defaultState() = 0;
	void setSpeed(float);
	void setDirection(float, float);
	void setDirection(const sf::Vector2f&);
	float getSpeed();
	sf::Vector2f getDirection();
	static sf::Vector2f normalizeVector(const sf::Vector2f&); //Đơn vị hoá vector
	static double vectorLength(const sf::Vector2f&); //Tính chiều dài vector
	static double dotProduct(const sf::Vector2f&, const sf::Vector2f&); //Tích vô hướng
	static double angleInDegree(const sf::Vector2f&); //Góc vector với trục hoành (chú ý: góc ngược xuống dưới)
	static sf::Vector2f rolateVector(const sf::Vector2f&, float); //Xoay vector một góc cho trước ngược chiều kim đồng hồ

};

#endif // !__MOVEABLEOBJECT_H__