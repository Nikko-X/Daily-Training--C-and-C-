/*
*虚函数 virtual
*如果子类对基类的方法进行了重定义，应该将二者都设为虚函数
*这样编译器会根据对象自动选择对应的类，而不会根据对应的指针或引用
*把基类的析构函数设置为虚函数是一种惯例，是为了确保释放子类对象时按正确顺序调用析构函数
*/
#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include <iostream>
#include <string>

class brass
{
public:
	brass(const std::string& fname = "NULL", long num = -1, double bal = 0.0);
	void deposit(double amt);	//存款
	virtual void wirhDraw(double amt);	//取款，设为虚函数，因为子类对其进行了重新定义
	double balan() const;		//余额
	virtual void viewAcct() const;	//查看账户
	virtual ~brass();

private:
	std::string fullName;
	long acctNum;
	double balance;
};

class brassPlus :public brass
{
public:
	brassPlus(const std::string& fname = "NULL", long num = -1, double bal = 0.0, double ml = 500, double ra = 0.11125);
	brassPlus(const brass& ba, double ml = 500, double ra = 0.11125);
	virtual void viewAcct() const;		//与基类行为不同，重新定义所以用虚函数(子类中可以不加 关键字 virtual)
	virtual void withDraw(double amt);
	void restMax(double m) { maxLoan = m; }	//调节最大借款
	void restRate(double r) { rate = r; }	//调节利息
	void restOwes() { owesBank = 0; }	//通过柜台人工置零

private:
	double maxLoan;
	double rate;
	double owesBank;
};


#endif // !BRASS_H_

