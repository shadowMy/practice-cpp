//#include<iostream>	可以删除
#include "mytime.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time& t) const			//返回对象不能是引用，因为这是个局部变量/临时变量，引用将指向不存在的数据。而返回Sum则是创建一个拷贝，调用的函数将得到这个拷贝。
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time& t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(double n) const
{
	Time result;
	long totalminutes = hours * n * 60 + minutes * n;
	result.minutes = totalminutes % 60;
	result.hours = totalminutes / 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;						//返回类型ostream
}	