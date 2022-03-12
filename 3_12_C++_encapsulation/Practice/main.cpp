/*练习：设计一个立方体类(cube)
*求出立方体的面积和体积
*分别用全局函数和成员函数判断两个立方体是否相等
*/
#include <iostream>

using namespace std;
class Cube
{
  public:
    //长
    void setL(double L)
    {
      m_L = L;
    }
    double getL()
    {
      return m_L;
    }
    //宽
    void setW(double W)
    {
      m_W = W;
    }
    double getW()
    {
      return m_W;
    }
    //高
    void setH(double H)
    {
      m_H = H;
    }
    double getH()
    {
      return m_H;
    } 
    //获取表面积
    double getArea()
    {
      return m_L*m_W*2 + m_L*m_H*2 + m_W*m_H*2;
    } 
    //获取体积
    double getVolume()
    {
      return m_H * m_L * m_W;
    }
    //利用成员函数判断是否相等
    bool isSameByClass(Cube &c)  //成员函数，是其中一个调用的，所以只需要一个参数即可
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
//利用全局函数判断2个立方体是否相等
bool isSame(Cube &c1 , Cube &c2)  //利用引用的方式传递，这样就不会拷贝一份，节省空间
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
  //cout <<"c1 立方体-->高度: " <<c1.getH() <<"  长度:  "<< c1.getL() << "  宽带:  " << c1.getW() << endl;
  cout <<"c1 立方体-->表面积:  " << c1.getArea() << "  体积:  " << c1.getVolume() << endl;

  Cube c2;
  c2.setH(10);
  c2.setL(10);
  c2.setW(10);
  //cout <<"c2 立方体-->高度: " <<c2.getH() <<"  长度:  "<< c2.getL() << "  宽带:  " << c2.getW() << endl;
  cout <<"c2 立方体-->表面积:  " << c2.getArea() << "  体积:  " << c2.getVolume() << endl;
  bool ret = isSame(c1,c2);
  if(true == ret)
    cout << "二者相等" << endl;
  else
    cout << "二者不相等" << endl;

  bool ret2 = c1.isSameByClass(c2);  //利用成员函数判断
  if(true == ret2)
    cout << "二者相等" << endl;
  else
    cout << "二者不相等" << endl;
  return 0;
}