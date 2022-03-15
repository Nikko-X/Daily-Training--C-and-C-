#include <iostream>

/*运算符的重载：对已有运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型*/
using namespace std;

//加号运算符重载
class Person
{
 public:
	 int m_A;
	 int m_B;
	 //成员函数重载+号  注意函数名称的写法必须为 operator+() 
	 //不然后面不可以直接用+号
	// Person operator+(Person& p)
	// {
	//	 Person temp{};		//temp要加上{}不然报错，视频里面没加
	//	 temp.m_A = this->m_A + p.m_A;
	//	 temp.m_B = this->m_B + p.m_B;
	//	 return temp;
	// }
 //private:
	
};
//全局函数重载+ 号

Person operator+(Person &p1, Person &p2)
{
	Person temp{};		//temp要加上{}不然报错，视频里面没加
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//运算符重载也可包含函数重载<-(函数名称一样，传入参数不同等等)
Person operator+(Person& p1, int num)
{
	Person temp{};		//temp要加上{}不然报错，视频里面没加
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01()
{
	Person p1{};
	p1.m_A = 10;
	p1.m_B = 15;

	Person p2{};
	p2.m_A = 5;
	p2.m_B = 10;

	//Person p3 = p1 + p2;	//这一行就是调用，可直接使用 + 号
	Person p3 = p1 + 20;	//利用了函数重载
	//Person p3 = p1.operator+(p2);//成员函数重载本质上是这样的，也就是系统会将+ 号自动识别为这个样子
	//Person p3 = operator+(p1, p2);//全局函数重载本质调用
	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
}

//左移运算符 << 重载 目的可以 输出 自定义数据类型
class Student
{
public:
	int m_A;
	int m_B;
	//利用成员函数重载 左移运算符
	// 一般不用成员函数来重载左移运算符，因为无法实现 cout 在左侧，只能用全局的
	//void operator<<(cout)
	//{
	//}
};

//ostream & operator<<(ostream &cout, Student &p)	//本质 operator<<(cout,p) 简化 cout << p,一定要用引用& 标准的输入输出流，只有一个
//{
//	cout << p.m_A << p.m_B << endl;
//	return cout;	//链式编程思想，返回一个cout，后面可以接着调用cout
//}

//void test02()
//{
//	Student p{};
//	p.m_A = 10;
//	p.m_B = 10;
//	cout << p << endl;
//}

//递增运算符 cout << b++ 先输出后递增 cout << ++b 先递增后输出（输出为递增后面的值）
// 
//自定义整型
class MyInteger
{
public:
	friend ostream& operator<<(ostream& cout, MyInteger& myint);
	MyInteger()
	{
		m_Num = 0;
	}
	//重载++运算符（前置）
	MyInteger& operator++()		//一定要加一个引用符&(这里指的是返回一个引用),目的是为了一直对一个数进行操作，
								//因为引用就是对对象本身进行操作，不会复制一个（如果是返回一个值的话就会自动创建一个新对象）
	{
		m_Num++;
		return *this;	//将自身做一个返回,返回的是一个引用
	}

	//重载++运算符（后置）
	MyInteger operator++(int)	//返回值不能作为函数重载的条件 所以加一个int （int 代表占位参数），用于区分前置和后置
								//（系统只能识别int,写其他类型，编译器不能识别是在写运算符重载的函数）
	{
		MyInteger temp = *this;	//先记录当时结果
		m_Num++;				//后递增
		return temp;			//返回的是一个值，因为这里的temp是一个临时变量，该函数结束后会销毁，所以只能返回值

	}
private:
	int m_Num;
};

//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger& myint)	//本质 operator<<(cout,p) 简化 cout << p,一定要用引用& 标准的输入输出流，只有一个
{
	cout << myint.m_Num << endl;
	return cout;	//链式编程思想，返回一个cout，后面可以接着调用cout
}

void test03()
{
	MyInteger myint{};
	//cout << ++(++myint) << endl;
	//cout << myint++;	//后置递增这样写报错
}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}