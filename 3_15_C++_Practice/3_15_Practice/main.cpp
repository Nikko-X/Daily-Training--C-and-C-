#include <iostream>

/*����������أ���������������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������*/
using namespace std;

//�Ӻ����������
class Person
{
 public:
	 int m_A;
	 int m_B;
	 //��Ա��������+��  ע�⺯�����Ƶ�д������Ϊ operator+() 
	 //��Ȼ���治����ֱ����+��
	// Person operator+(Person& p)
	// {
	//	 Person temp{};		//tempҪ����{}��Ȼ������Ƶ����û��
	//	 temp.m_A = this->m_A + p.m_A;
	//	 temp.m_B = this->m_B + p.m_B;
	//	 return temp;
	// }
 //private:
	
};
//ȫ�ֺ�������+ ��

Person operator+(Person &p1, Person &p2)
{
	Person temp{};		//tempҪ����{}��Ȼ������Ƶ����û��
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//���������Ҳ�ɰ�����������<-(��������һ�������������ͬ�ȵ�)
Person operator+(Person& p1, int num)
{
	Person temp{};		//tempҪ����{}��Ȼ������Ƶ����û��
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

	//Person p3 = p1 + p2;	//��һ�о��ǵ��ã���ֱ��ʹ�� + ��
	Person p3 = p1 + 20;	//�����˺�������
	//Person p3 = p1.operator+(p2);//��Ա�������ر������������ģ�Ҳ����ϵͳ�Ὣ+ ���Զ�ʶ��Ϊ�������
	//Person p3 = operator+(p1, p2);//ȫ�ֺ������ر��ʵ���
	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
}

//��������� << ���� Ŀ�Ŀ��� ��� �Զ�����������
class Student
{
public:
	int m_A;
	int m_B;
	//���ó�Ա�������� ���������
	// һ�㲻�ó�Ա�����������������������Ϊ�޷�ʵ�� cout ����ֻ࣬����ȫ�ֵ�
	//void operator<<(cout)
	//{
	//}
};

//ostream & operator<<(ostream &cout, Student &p)	//���� operator<<(cout,p) �� cout << p,һ��Ҫ������& ��׼�������������ֻ��һ��
//{
//	cout << p.m_A << p.m_B << endl;
//	return cout;	//��ʽ���˼�룬����һ��cout��������Խ��ŵ���cout
//}

//void test02()
//{
//	Student p{};
//	p.m_A = 10;
//	p.m_B = 10;
//	cout << p << endl;
//}

//��������� cout << b++ ���������� cout << ++b �ȵ�������������Ϊ���������ֵ��
// 
//�Զ�������
class MyInteger
{
public:
	friend ostream& operator<<(ostream& cout, MyInteger& myint);
	MyInteger()
	{
		m_Num = 0;
	}
	//����++�������ǰ�ã�
	MyInteger& operator++()		//һ��Ҫ��һ�����÷�&(����ָ���Ƿ���һ������),Ŀ����Ϊ��һֱ��һ�������в�����
								//��Ϊ���þ��ǶԶ�������в��������Ḵ��һ��������Ƿ���һ��ֵ�Ļ��ͻ��Զ�����һ���¶���
	{
		m_Num++;
		return *this;	//��������һ������,���ص���һ������
	}

	//����++����������ã�
	MyInteger operator++(int)	//����ֵ������Ϊ�������ص����� ���Լ�һ��int ��int ����ռλ����������������ǰ�úͺ���
								//��ϵͳֻ��ʶ��int,д�������ͣ�����������ʶ������д��������صĺ�����
	{
		MyInteger temp = *this;	//�ȼ�¼��ʱ���
		m_Num++;				//�����
		return temp;			//���ص���һ��ֵ����Ϊ�����temp��һ����ʱ�������ú�������������٣�����ֻ�ܷ���ֵ

	}
private:
	int m_Num;
};

//�������������
ostream& operator<<(ostream& cout, MyInteger& myint)	//���� operator<<(cout,p) �� cout << p,һ��Ҫ������& ��׼�������������ֻ��һ��
{
	cout << myint.m_Num << endl;
	return cout;	//��ʽ���˼�룬����һ��cout��������Խ��ŵ���cout
}

void test03()
{
	MyInteger myint{};
	//cout << ++(++myint) << endl;
	//cout << myint++;	//���õ�������д����
}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}