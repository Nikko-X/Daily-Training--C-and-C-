#include "stringbad.h"
#include <cstring>
#pragma warning( disable : 4996)

using std::cout;

int stringBad::num_strings = 0;	//初始化静态变量，是可以的
stringBad::stringBad()
{
	num_strings++;
	len = 4;
	str = new char[4];
	//str[0] = '\0';
	//str = 0;	//与上面等价
	strcpy_s(str, 4 ,"C++");	
	//strcpy(str,"C++");	//用strcpy理论上是可以的，但是编译器会报错，可以加上:#pragma warning( disable : 4996)
	cout <<"无参构造一个字符串："<< str << " 编号为:" << num_strings << std::endl;
}

stringBad::stringBad(const char* s)
{
	num_strings++;
	len = std::strlen(s);
	str = new char [len + 1];		//还有一个 /0 所以要加1
	strcpy_s(str, len + 1 ,s);
	cout << "有参构造一个字符串：" << str << " 编号为:" << num_strings << std::endl;
}

std::ostream& operator<<(std::ostream os, const stringBad& st)
{
	os  << st.str;	//传进来是一个引用
	return os;
}

bool operator<(const stringBad& st1, const stringBad& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const stringBad& st1, const stringBad& st2)
{
	return (std::strcmp(st1.str, st2.str) > 0);
}

bool operator==(const stringBad& st1, const stringBad& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

char& stringBad::operator[](int i)	//类内实现
{
	return str[i];
}
//char& operator[](stringBad str)	//类外实现不允许
//{
//	return str[i];
//}

/*解决浅拷贝问题一般都需要下面2个函数*/
stringBad::stringBad(const stringBad& s)	//拷贝构造函数
{
	num_strings++;		//创建新对象了，所以加1
	len = s.len;		//进行赋值，可能用到了下面的赋值操作
	str = new char[len + 1];	//申请新地址
	std::strcpy(str, s.str);
	cout << "拷贝构造函数调用： " << "编号： " << num_strings << std::endl;
}
/*赋值操作先释放了内存再重新申请内存，总体是没有加新内存的，也可以看出没创建新对象*/
stringBad& stringBad::operator=(const stringBad& st)	//赋值操作，不创建新对象
{
	if (this == &st)	//检查是不是自我复制
		return *this;
	delete[] str;	//释放str指向的内存(释放原来储存的数据)（待会要把传进来的复制进去）
	len = st.len;	
	str = new char[len + 1];	//重新分配内存
	std::strcpy(str, st.str);
	return *this;	//返回调用对象的引用，这样可以可以实现 a = b =c 等的操作
}

stringBad::~stringBad()
{
	cout << "删除编号: " << num_strings << " 其字符串： " << str << std::endl;
	delete[] str;	//删去一个数组空间，[]不能忘记
	--num_strings;
}

//void callme1(stringBad & rbs)
//{
//	cout << "召回显示：";
//	cout << rbs;
//}

//void callme2(stringBad st)
//{
//	cout << st;
//}
