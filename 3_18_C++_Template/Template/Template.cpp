#include <iostream>
using namespace std;

////2个整型交换
//void swapInt(int &a,int &b)		//引用的方式进行交换，会将本体也进行交换
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////交换2个浮点型
//void swapDouble(double &a,double &b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}

//函数模板
//声明一个模板，告诉编译器 后面代码中紧跟着的T不要报错，T是一个通用的数据类型
template <class T>
void  mySwap(T	&a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//void test01()
//{
//	int a = 10;
//	int b = 20;
//	//利用函数模板进行交换
//	//2种方式
//	//1、自动推导
//	//mySwap(a,b);
//
//	//2、显示指定类型
//	mySwap<int>(a,b);
//	//swapInt(a,b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}

//实现一个通用的数组排序函数
//从大到小，选择排序
//排序算法

template <class T>
void mySort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;	//认定最大值下标
		for (int j = i +1;j <len;j++)
		{
			//认定的最大值比遍历出的最大值要小，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j; //更换最大值下标
			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);//交换max和i
		}
	}
}
void test02()
{
	char charArr[] = "bafge";
	mySort(charArr,sizeof(charArr));
	cout << charArr << endl;
}

int main()
{
	//test01();
	test02();
	return 0;
}

