/*运算符重载书本知识练习*/
#include "mytime0.h"
using namespace std;

int main()
{
    Time planning;
    Time coding(2, 40);
    Time fixing(5,55);
    Time coding1(2, 40);
    Time fixing1(2, 5);
    Time total;
    Time total_2;

    cout << "planning time = ";
    planning.show();

    cout << "coding time = ";
    coding.show();

    cout << "fixing time = ";
    fixing.show();
    
    total = coding.sum(fixing);     //接收返回对象的副本
    cout << "coding.sum(fixing): ";
    total.show();

    total_2 = coding1 + fixing1;    //加法运算符重载
    /*加法重载运算符可以实现 t1 = t2 + t3 + t4
    *转换成原型: t1 = t2.operator+(t3 + t4),
    * 函数首先会调用 t2.operator(t3),返回一个对象，再由这个对象调用operator+,一直最后返回总的和
    * 所以连续加好多都可以
    */

    //total_2 = coding1.operator+(fixing1);   //+ 运算符重载原型可这样调用的
    cout << "coding1 + fixing1: ";
    total_2.show();

    total_2 = coding1 - fixing1;
    cout << "coding1 - fixing1: ";
    total_2.show();

    total_2 = coding1 * fixing1;
    cout << "coding1 * fixing1: ";
    total_2.show();

    total_2 = coding1 / fixing1;
    cout << "coding1 / fixing1: ";
    total_2.show();
    
    total_2 = 2.5 * fixing1;
    cout << "2.5 * fixing1: ";
    total_2.show();

    cout << coding;

    return 0;
}
