#pragma once
#ifndef MYTIME0_H_
#define MYTIME0_H_
#include <iostream>		//ͷ�ļ���������
class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time& t) const;	
	Time operator+(const Time& t) const;	//�ӷ���������ش������溯��,�亯����������һ��������ʹ��
	Time operator-(const Time& t) const;
	Time operator*(const Time& t) const;
	Time operator/(const Time& t) const;
	void show() const;
	~Time();
	friend Time operator*(double m, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);	//Ҫ����cout ���ڵ��࣬�����Ǽ������򣬷���os ����ʵ����ʽ���
private:
	int hours;
	int minutes;
};
#endif // !MYTIME0_H_
