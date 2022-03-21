
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*例程理解练习，输出流*/
//void file_it(ostream& os, double fo, const double fe[], int n);
//const int LIMIT = 5;
//int main()
//{
//	ofstream fout;		//用ofstream类,创建一个对象
//	const char* fn = "ep_data.txt";
//	fout.open(fn);		//打开或创建一个名为 ep_data.txt 的文件
//	if (!fout.is_open())	//打开失败
//	{
//		cout << "Can't open " << fn << " Bye.\n";
//		exit(EXIT_FAILURE);
//	}
//	double objective;
//	cout << "Enter the focal length of your" << " telescope objective in mm: ";	
//	cin >> objective;	//输入物镜参数
//	double eps[LIMIT];
//	cout << "Enter the focal lengths,in mm, of" << LIMIT
//		 << " eyepieces: \n";	//输入5个目镜参数
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "EYepiece #" << i + 1 << ": ";
//		cin >> eps[i];
//	}
//	file_it(fout, objective, eps, LIMIT);	//写入前面打开的的文件中
//	file_it(cout, objective, eps, LIMIT);	//输出显示
//	return 0;
//}
//
//void file_it(ostream& os, double fo, const double fe[], int n)
//{
//	ios_base::fmtflags initial;
//	initial = os.setf(ios_base::fixed);	//保存初始化格式装态，将对象置于使用定点表示法模式
//	os.precision(0);	//设置输出精度（显示多少位小数）
//	os << "Focal length of objective: " << fo << " mm\n";
//	os.setf(ios_base::showpoint);	//显示小数点模式
//	os.precision(1);
//	os.width(12);
//	os << "f.1. eyepiece";
//	os.width(15);
//	os << "magnification" << endl;
//	for (int i = 0;i < n ; i++)
//	{
//		os.width(12);
//		os << fe[i];
//		os.width(15);
//		os << int(fo / fe[i] + 0.5) << endl;
//	}
//	os.setf(initial);	//恢复初始状态
//}

/*函数模板简单练习，学习书本8.5 理解
*重载的模板
* 显示实例化(为特定的模板提供具体化的模板定义)
* 实例化与具体化
*/

//函数模板
template <class T>
void mSwap(T& a, T& b);

//重载函数模板 
//该示例功能：交换数组前几位元素 由传入参数最后一位决定
template <class T>
void mSwap(T* a, T* b, int n);

struct job
{
	string name;
	double salary;
	int floor;
};
//显示实列化模板函数(运算符重载可代替)
template<> void mSwap<job>(job& j1, job& j2);
void show(job &j);
int main()
{
	int x1 = 10;
	int x2 = 15;
	mSwap(x1, x2);
	cout << "x1: " << x1 
		 << " x2: " << x2 << endl;

	double x3 = 10.22;
	double x4 = 15.33;
	mSwap(x3, x4);
	cout << "x3: " << x3
		 << " x4: " << x4 << endl;

	int arr1[] = {1,2,3,4,5,6};
	int arr2[] = { 6,5,4,3,2,1 };
	mSwap(arr1,arr2,3);

	cout << "arr1: ";
	for (int i = 0; i < 6; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	cout << "arr2: ";
	for (int i = 0; i < 6; i++)
	{
		cout << arr2[i] << " ";
	}
	job j1 = {"Huawei",15000.4, 8 };
	job j2 = { "Xiaomi",16000,9 };
	cout << endl;
	cout << "Befor Swap" << endl;
	show(j1);
	show(j2);
	cout << "After Swap" << endl;
	mSwap(j1,j2);
	show(j1);
	show(j2);

	return 0;
}
//函数模板
template <class T>
void mSwap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

//重载的模板
template <class T>
void mSwap(T a[], T b[], int n)	//数组的名称就是地址，这样写可以告诉编译器传入的是一个数组
{
	T temp;
	for (T i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

//显示实例化函数模板
//示例交换2者salary和floor
template<> void mSwap<job>(job& j1, job& j2)
{
	double s1;
	s1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = s1;

	int f1;
	f1 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = f1;
}
void show(job& j)
{
	cout << "Name: " << j.name << endl;
	cout << "Salary: " << j.salary << endl;
	cout << "Floor: " << j.floor << endl;
}