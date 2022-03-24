#include "mytime0.h"
Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::addHr(int h)
{
	hours += h;
}
void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}
Time Time::sum(const Time& t) const		//以引用的方式传入
{
	Time sum;
	sum.minutes = t.minutes + this->minutes;
	sum.hours = t.hours + this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//返回的是一个Time类型的值（将创建对象的副本），不是一个指针或引用，当然是可以的
}
void Time::show() const
{
	std::cout << hours << "hours, " << minutes << "minutes\n";
}

Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes + this->minutes;
	sum.hours = t.hours + this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//返回的是一个Time类型的值（将创建对象的副本），不是一个指针或引用，当然是可以的
}
Time Time::operator-(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes - this->minutes;
	sum.hours = t.hours - this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//返回的是一个Time类型的值（将创建对象的副本），不是一个指针或引用，当然是可以的
}
Time Time::operator*(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes * this->minutes;
	sum.hours = t.hours * this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//返回的是一个Time类型的值（将创建对象的副本），不是一个指针或引用，当然是可以的
}
Time Time::operator/(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes / this->minutes;
	sum.hours = t.hours / this->hours;
	//sum.minutes %= 60;
	return sum;	//返回的是一个Time类型的值（将创建对象的副本），不是一个指针或引用，当然是可以的
}
Time operator*(double m, const Time& t)	//友元函数，没有作用域，同样是*的重载，实现2个不同的数据类型相乘
{
	Time mun;
	mun.hours = t.hours * m;
	mun.minutes = t.minutes;
	return mun;
}

std::ostream&  operator<<(std::ostream& os, const Time& t)
{
	//using namespace std;
	os << "hours: " << t.hours << " minutes: " << t.minutes << std::endl;
	return os;
}
Time::~Time()
{
	std::cout << "析构函数调用\n";
}