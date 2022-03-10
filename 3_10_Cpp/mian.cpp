#include <iostream>

using namespace std;
int main(int argc,char* argv[])
{
  /*用new 在堆区开辟储存空间的用法
  *1.变量
  *2.数组
  */

  int *p = new int;
  *p = 10;
  int *p = new int(10);
  delete p; //释放空间
  
  int* arr = new int[20];//使用new开辟一个数组空间，返回的是一个首地址
  delete [] arr; //注意释放数组空间要加一个[]
  
  /*引用 的相关语法(给变量取别名)
   * 基本语法
   * 数据类型 &别名 = 原名
   * 注意事项：
   * 1、引用必须初始化
   * 2、引用在初始化后不可改变
   */

  int a = 10;
  int &b = a; //创建引用（必须初始化） int &b; 是不可以的
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  b = 20;   //通过修改b也可以修改a的值
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  return 0;
}

 /*引用做函数参数---->交换函数*/

//1、值传递  不会改变a和b的值  形参不会修饰实参
void mySwap01(int a,int b)
{
  int temp = a;
  a = b;
  b = temp;
}
//2、地址传递  会改变a和b的值  形参会修饰实参
void mySwap02(int* a,int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
//3、引用传递  会改变  形参会修饰实参
void mySwap03(int &a,int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

/*引用做函数的返回值
*1、不要返回局部变量的引用
*2、函数调用可以作为左值
*/
int& test01()    //加了一个& 表示以引用的方式返回，接收时应该用 int &ref = test()
{
  int a = 10;
  return a;   //这样返回是错误的
}

int& test02()
{
  static int a = 10;    //加一个static 就不是局部变量了，是静态变量存在全局区
  return a;
}
//可以作为左值，代表在调用函数时 可以这样用test02() = 1000; 这其实是给a赋1000