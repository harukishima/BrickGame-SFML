#include "Date.h"

void Date::Now()
{
	time_t t;
	time(&t);
	tm TM;
	localtime_s(&TM, &t);
	hour = TM.tm_hour;
	minute = TM.tm_min;
	second = TM.tm_sec;
	day = TM.tm_mday;
	month = TM.tm_mon;
	year = TM.tm_year + 1900;
}

void Date::print()
{
	cout << hour << ":" << minute << ":" << second << "   " << day << "/" << month << "/" << year;
}

ostream& operator<<(ostream& out, Date& scr)
{
	//out << scr.hour << "," << scr.minute << "," << scr.second << "," << scr.day << "," << scr.month << "," << scr.year;
	out << scr.hour << ":" << scr.minute << ":" << scr.second << "   " << scr.day << "/" << scr.month << "/" << scr.year;
	return out;
}
