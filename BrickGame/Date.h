#ifndef __DATE_H__
#define __DATE_H__

#include<ctime>
#include<iostream>
using namespace std;

class Date
{
public:
	int hour, minute, second;
	int day, month, year;
	void Now();
	void print();
	friend ostream& operator<<(ostream& out, Date& scr);
};




#endif // !__DATE_H__



