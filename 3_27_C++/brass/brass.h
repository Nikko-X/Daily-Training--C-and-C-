/*
*�麯�� virtual
*�������Ի���ķ����������ض��壬Ӧ�ý����߶���Ϊ�麯��
*��������������ݶ����Զ�ѡ���Ӧ���࣬��������ݶ�Ӧ��ָ�������
*�ѻ����������������Ϊ�麯����һ�ֹ�������Ϊ��ȷ���ͷ��������ʱ����ȷ˳�������������
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
	void deposit(double amt);	//���
	virtual void wirhDraw(double amt);	//ȡ���Ϊ�麯������Ϊ���������������¶���
	double balan() const;		//���
	virtual void viewAcct() const;	//�鿴�˻�
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
	virtual void viewAcct() const;		//�������Ϊ��ͬ�����¶����������麯��(�����п��Բ��� �ؼ��� virtual)
	virtual void withDraw(double amt);
	void restMax(double m) { maxLoan = m; }	//���������
	void restRate(double r) { rate = r; }	//������Ϣ
	void restOwes() { owesBank = 0; }	//ͨ����̨�˹�����

private:
	double maxLoan;
	double rate;
	double owesBank;
};


#endif // !BRASS_H_

