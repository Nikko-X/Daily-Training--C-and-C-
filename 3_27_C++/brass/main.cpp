#include "brass.h"
#include <iostream>
using namespace std;
int main()
{
    brass Nikko("Niko001", 2134543, 2000);
    brass Tom("Tom001", 123456, 1000);
    brassPlus Tim("Tim_VIP1", 888888, 5000);
    Nikko.wirhDraw(2500);
    cout << endl;
    Tim.withDraw(5500);
    Tim.viewAcct();
    cout << endl;
    Tim.restOwes();
    Tim.viewAcct();
    cout << endl;

    brass& N1 = Nikko;  //父类 引用、指针可以 引用、指向 子类或者父类
    brass* T1 = &Tim;   //调用那个类方法:写了虚函数后根据为其调用的 对象 的基本类型 来解析对虚函数的调用
                        //不写默认根据 指针或引用 的类型 来解析对非虚函数的调用
    N1.viewAcct();
    T1->viewAcct();
}
