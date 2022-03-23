// stock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "stock10.h"

int main()
{
    Stock temp{};
    Stock hot_tip = {"C Pluse Pluse",10,45.5};
    Stock hot = { "Abanden"};   //在函数声明处定义了初值，后面2个参数不赋值默认为0，千万注意函数定义处和函数声明处的不同
    temp.show();
    hot_tip.show();
    hot.show();
}
