/*��ϰ�����һ����������(cube)
*������������������
*�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
*/
#include <iostream>

using namespace std;
class Cube
{
  public:
    //��
    void setL(double L)
    {
      m_L = L;
    }
    double getL()
    {
      return m_L;
    }
    //��
    void setW(double W)
    {
      m_W = W;
    }
    double getW()
    {
      return m_W;
    }
    //��
    void setH(double H)
    {
      m_H = H;
    }
    double getH()
    {
      return m_H;
    } 
    //��ȡ�����
    double getArea()
    {
      return m_L*m_W*2 + m_L*m_H*2 + m_W*m_H*2;
    } 
    //��ȡ���
    double getVolume()
    {
      return m_H * m_L * m_W;
    }
    //���ó�Ա�����ж��Ƿ����
    bool isSameByClass(Cube &c)  //��Ա������������һ�����õģ�����ֻ��Ҫһ����������
    {
      if(m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
        return true;
      else
        return false;
    }
  private:
    double m_L;
    double m_W;
    double m_H;
};
//����ȫ�ֺ����ж�2���������Ƿ����
bool isSame(Cube &c1 , Cube &c2)  //�������õķ�ʽ���ݣ������Ͳ��´��һ�ݣ���ʡ�ռ�
{
  if(c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
    return true;
  else
    return false;
}
int main()
{
  Cube c1;
  c1.setH(10);
  c1.setL(10);
  c1.setW(11);
  //cout <<"c1 ������-->�߶�: " <<c1.getH() <<"  ����:  "<< c1.getL() << "  ���:  " << c1.getW() << endl;
  cout <<"c1 ������-->�����:  " << c1.getArea() << "  ���:  " << c1.getVolume() << endl;

  Cube c2;
  c2.setH(10);
  c2.setL(10);
  c2.setW(10);
  //cout <<"c2 ������-->�߶�: " <<c2.getH() <<"  ����:  "<< c2.getL() << "  ���:  " << c2.getW() << endl;
  cout <<"c2 ������-->�����:  " << c2.getArea() << "  ���:  " << c2.getVolume() << endl;
  bool ret = isSame(c1,c2);
  if(true == ret)
    cout << "�������" << endl;
  else
    cout << "���߲����" << endl;

  bool ret2 = c1.isSameByClass(c2);  //���ó�Ա�����ж�
  if(true == ret2)
    cout << "�������" << endl;
  else
    cout << "���߲����" << endl;
  return 0;
}