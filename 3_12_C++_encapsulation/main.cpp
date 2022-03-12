#include<iostream>
#include<string>

using namespace std;
//class--->类

const double pi = 3.14;
//设计一个圆类，求圆的周长
//圆求周长的公式为 2*PI*半径

//class 代表设计一个类，类后面紧跟着的就是类的名称
class Circle
{
  //访问权限
  public:   //公共权限

  //属性
  int m_r;   //半径

  //行为-->获取圆的周长
  double calculateZC()
  {
    return 2 * pi * m_r;
  }
};    //注意分号

//设计一个学生类，属性有姓名、学号，可以给姓名、学号赋值，可以显示学生的姓名、学号
class Student
{
  //权限
  public:

  //类中的属性和行为 我们统一称为：成员

  //属性 -->也叫 成员属性、成员变量
  string stName;
  string number;

  //行为  --> 成员函数、成员方法

  //可以通过行为，来给属性赋值
  string calculateName()
  {
    return stName;
  }

  string calculateNum()
  {
    return number;
  }
  void setName(string name) //给名字赋值
  {
    stName = name;
  }
};

//访问权限 --> 三种
//公共权限:public  --> 成员 在类内可以访问，类外也可以访问
//保护权限:protected -->成员 类内可以访问，类外不可以访问
//私有权限:private --> 成员 类内可以访问，类外不可以访问 （在继承中与protected不同）

class Person
{
  public:
  //公共权限
    string m_Name;
  protected:
  //保护权限
    string m_Car;
  private:
  //私有权限
    int m_Password;

  public:
    void func()
    {
      m_Name = "张三";
      m_Car = "小摩托";
      m_Password = 123456;  //在这个类里面，每个成员都是可以访问的
    }
};

//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写可以检测数据的有效性

//通过提供一个公共的成员函数作为对外接口，来进行赋值等操作
//设计人 类
class Pers
{
public:
  void set_Name(string name)  //写姓名
  {
    m_Name = name;
  }

  string get_Name() //读姓名
  {
    return m_Name;
  }

  void set_Age(int age)  //写姓名
  {
    if(age < 0 || age > 150)  //检测数据有效性
    {
      m_Age = 0;    //设置为默认值0
      cout << "范围错误" << endl;
      return;
    }
    m_Age = age;
  }
  int  get_Age() //读年龄
  {
    //m_Age = 15;
    return m_Age;
  }
private:
  string m_Name;  //姓名 可读可写
  int m_Age;    //年纪  可读可写（范围必须是0 ~ 150）
  string m_Lover; //爱人 只写
};


int main()
{
  //通过圆类 创建一个具体的圆（对象）
  Circle c1;
  //给圆对象的属性进行赋值
  c1.m_r = 10;
  cout << "圆的周长为: " << c1.calculateZC() << endl;

  Student student1;
  //student1.stName = "张三";
  student1.setName("张三");
  student1.number = "123456";
  cout << "studdent1 名字: " << student1.calculateName() << " 学号: " << student1.calculateNum();

  Person p1;
  p1.m_Name = "李四";
  //p1.m_Car = "汽车";  //protect 在类外是不可以访问的，就不能修改
  return 0;
}