#include "stock10.h"
#include <iostream>

Stock::Stock()	//����ṩ���вι��캯�����ͱ����ṩĬ�Ϲ��죨��Ȼÿ�����ɶ��󶼱��봫�ݲ�����ȥ����ϵͳ����Ĭ���ṩ
{
	std::cout << "�޲�(Ĭ��)����\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr)	//ͷ�ļ��к����������Դ������������ﺯ�������ǲ����Դ������ģ���Ȼ�ᱨ��
{
	std::cout << "�вι���\n";
	company = co;
	if (n < 0)
		shares = 0;
	else
	shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock()		//������캯���ö�̬�ڴ��ˣ���������һ��Ҫ�����ͷţ���ֹ�����ڴ�й¶
{
	std::cout << "������������\n";
}
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "�Ҳ�������";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}


}
void Stock::sell(long num, double price)
{

}
void Stock::update(double price)
{

}
void Stock::show()
{
	std::cout << "Name: " << this->company << std::endl 
			  << "shares: " << this->shares << std::endl 
			  << "total_val: " << this->total_val << std::endl;
}
