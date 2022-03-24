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
Time Time::sum(const Time& t) const		//�����õķ�ʽ����
{
	Time sum;
	sum.minutes = t.minutes + this->minutes;
	sum.hours = t.hours + this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//���ص���һ��Time���͵�ֵ������������ĸ�����������һ��ָ������ã���Ȼ�ǿ��Ե�
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
	return sum;	//���ص���һ��Time���͵�ֵ������������ĸ�����������һ��ָ������ã���Ȼ�ǿ��Ե�
}
Time Time::operator-(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes - this->minutes;
	sum.hours = t.hours - this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//���ص���һ��Time���͵�ֵ������������ĸ�����������һ��ָ������ã���Ȼ�ǿ��Ե�
}
Time Time::operator*(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes * this->minutes;
	sum.hours = t.hours * this->hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;	//���ص���һ��Time���͵�ֵ������������ĸ�����������һ��ָ������ã���Ȼ�ǿ��Ե�
}
Time Time::operator/(const Time& t) const
{
	Time sum;
	sum.minutes = t.minutes / this->minutes;
	sum.hours = t.hours / this->hours;
	//sum.minutes %= 60;
	return sum;	//���ص���һ��Time���͵�ֵ������������ĸ�����������һ��ָ������ã���Ȼ�ǿ��Ե�
}
Time operator*(double m, const Time& t)	//��Ԫ������û��������ͬ����*�����أ�ʵ��2����ͬ�������������
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
	std::cout << "������������\n";
}