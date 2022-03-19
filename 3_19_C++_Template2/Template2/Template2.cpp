/*主要内容：
* 类模板对象做函数参数
* 类模板与继承
* 类模板成员函数类外实现
*/

#include <iostream>
#include <string>
using namespace std;

//模板对象做函数参数

template<class T1,class T2>
class Person
{
public:
    Person(T1 name, T2 age) //构造函数
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "姓名：" << this->m_Name << endl;
        cout << "年龄：" << this->m_Age << endl;
    }
    T1 m_Name;
    T2 m_Age;
};

//指定传入类型（最常用）
void printPerson01(Person<string, int>&p)   //直接说明类型 用引用的方式 传入
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("孙悟空",100);   //利用Person 这个类创建一个对象 p
    printPerson01(p);
}

//参数模板化
template<class T1,class T2>
void printPerson02(Person<T1,T2> &p)
{
    p.showPerson();
}
void test02()
{
    Person<string, int> p("猪八戒", 90);   //利用Person 这个类创建一个对象 p
    printPerson02(p);
}

//整个类模板化
template<class T>
void printPerson03(T &p)
{
    p.showPerson();
}
void test03()
{
    Person<string, int> p("沙和尚", 105);
    printPerson03(p);
}

//类模板与继承

template<class T>
class Base
{
public:
    T m;
};
//class son :public Base //正常这样的继承写法是错的，子类继承父类的模板是必须指定父类模板中的数据类型
class son : public Base<int>
{
    
};
void test04()
{
    son s1;
}
//想要灵活的指定父类T的数据类型，子类也需要变成模板
template<class T1,class T2>
class son2 : public Base<T1>
{
public:
    son2()          //构造函数,构建这个类时，自动调用
    {
        cout << "T1的数据类型为" << typeid(T1).name() << endl;    //打印T1的数据类型
        cout << "T2的数据类型为" << typeid(T2).name() << endl;
    }
    T2 obj;
};

void test05()
{
    son2<int,char> s2;  //这里面的int char 分别传给了T1 T2
}

//类模板成员函数类外实现
template <class T1,class T2>
class Person2
{
public:
    Person2(T1 name, T2 age);   //类外实现，里面只做声明
    //{
    //    this->m_Name = name;
    //    this->m_Age = age;
    //}

    void showPerson();
    //{
    //    cout << "姓名：" << m_Name << endl << "年龄：" << m_Age << endl;
    //}
    T1 m_Name;
    T2 m_Age;
};
//构造函数的类外实现
template<class T1,class T2>
Person2<T1,T2>::Person2(T1 name, T2 age)    //类模板与普通函数的类外实现，差别在于<>,作用域不能忘
{
    this->m_Name = name;
    this->m_Age = age;
}
//成员函数的类外实现
template<class T1, class T2>
void Person2<T1,T2>::showPerson()
{
    cout << "姓名：" << m_Name << endl << "年龄：" << m_Age << endl;
}
void test06()
{
    Person2<string,int> p("小明",18);
    p.showPerson();
}
int main()
{
    /*test01();
    test02();
    test03();
    */
    //test05();
    test06();
}

