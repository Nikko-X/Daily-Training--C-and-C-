#include "stock10.h"
#include <iostream>

Stock::Stock()	//如果提供了有参构造函数，就必须提供默认构造（不然每次生成对象都必须传递参数进去），系统不会默认提供
{
	std::cout << "无参(默认)构造\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr)	//头文件中函数声明可以带参数，但这里函数定义是不可以带参数的（不然会报错）
{
	std::cout << "有参构造\n";
	company = co;
	if (n < 0)
		shares = 0;
	else
	shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock()		//如果构造函数用动态内存了，析构函数一定要将其释放，防止产生内存泄露
{
	std::cout << "析构函数调用\n";
}
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "找不到数量";
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
