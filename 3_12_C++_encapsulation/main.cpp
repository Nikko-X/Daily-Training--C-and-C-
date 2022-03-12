#include<iostream>
#include<string>

using namespace std;
//class--->��

const double pi = 3.14;
//���һ��Բ�࣬��Բ���ܳ�
//Բ���ܳ��Ĺ�ʽΪ 2*PI*�뾶

//class �������һ���࣬���������ŵľ����������
class Circle
{
  //����Ȩ��
  public:   //����Ȩ��

  //����
  int m_r;   //�뾶

  //��Ϊ-->��ȡԲ���ܳ�
  double calculateZC()
  {
    return 2 * pi * m_r;
  }
};    //ע��ֺ�

//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student
{
  //Ȩ��
  public:

  //���е����Ժ���Ϊ ����ͳһ��Ϊ����Ա

  //���� -->Ҳ�� ��Ա���ԡ���Ա����
  string stName;
  string number;

  //��Ϊ  --> ��Ա��������Ա����

  //����ͨ����Ϊ���������Ը�ֵ
  string calculateName()
  {
    return stName;
  }

  string calculateNum()
  {
    return number;
  }
  void setName(string name) //�����ָ�ֵ
  {
    stName = name;
  }
};

//����Ȩ�� --> ����
//����Ȩ��:public  --> ��Ա �����ڿ��Է��ʣ�����Ҳ���Է���
//����Ȩ��:protected -->��Ա ���ڿ��Է��ʣ����ⲻ���Է���
//˽��Ȩ��:private --> ��Ա ���ڿ��Է��ʣ����ⲻ���Է��� ���ڼ̳�����protected��ͬ��

class Person
{
  public:
  //����Ȩ��
    string m_Name;
  protected:
  //����Ȩ��
    string m_Car;
  private:
  //˽��Ȩ��
    int m_Password;

  public:
    void func()
    {
      m_Name = "����";
      m_Car = "СĦ��";
      m_Password = 123456;  //����������棬ÿ����Ա���ǿ��Է��ʵ�
    }
};

//��Ա��������Ϊ˽��
//1�������Լ����ƶ�дȨ��
//2������д���Լ�����ݵ���Ч��

//ͨ���ṩһ�������ĳ�Ա������Ϊ����ӿڣ������и�ֵ�Ȳ���
//����� ��
class Pers
{
public:
  void set_Name(string name)  //д����
  {
    m_Name = name;
  }

  string get_Name() //������
  {
    return m_Name;
  }

  void set_Age(int age)  //д����
  {
    if(age < 0 || age > 150)  //���������Ч��
    {
      m_Age = 0;    //����ΪĬ��ֵ0
      cout << "��Χ����" << endl;
      return;
    }
    m_Age = age;
  }
  int  get_Age() //������
  {
    //m_Age = 15;
    return m_Age;
  }
private:
  string m_Name;  //���� �ɶ���д
  int m_Age;    //���  �ɶ���д����Χ������0 ~ 150��
  string m_Lover; //���� ֻд
};


int main()
{
  //ͨ��Բ�� ����һ�������Բ������
  Circle c1;
  //��Բ��������Խ��и�ֵ
  c1.m_r = 10;
  cout << "Բ���ܳ�Ϊ: " << c1.calculateZC() << endl;

  Student student1;
  //student1.stName = "����";
  student1.setName("����");
  student1.number = "123456";
  cout << "studdent1 ����: " << student1.calculateName() << " ѧ��: " << student1.calculateNum();

  Person p1;
  p1.m_Name = "����";
  //p1.m_Car = "����";  //protect �������ǲ����Է��ʵģ��Ͳ����޸�
  return 0;
}