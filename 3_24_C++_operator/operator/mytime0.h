#pragma once
#ifndef MYTIME0_H_
#define MYTIME0_H_
#include <iostream>		//头文件不能忘记
class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time& t) const;	
	Time operator+(const Time& t) const;	//加法运算符重载代替上面函数,其函数定义内容一样，方便使用
	Time operator-(const Time& t) const;
	Time operator*(const Time& t) const;
	Time operator/(const Time& t) const;
	void show() const;
	~Time();
	friend Time operator*(double m, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);	//要包含cout 所在的类，别忘记加作用域，返回os 可以实现链式输出
private:
	int hours;
	int minutes;
};
#endif // !MYTIME0_H_
