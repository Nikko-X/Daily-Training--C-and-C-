#include<iostream>

int main()
{

  using namespace std;
  /*int tall;
  cout << "Please input your tall __";
  cin >> tall;
  cout << endl;
  cout << tall << " M is " << tall*10 << "CM" << endl;
  /******************************************************************************************/

  /*int feet;
  int inch;
  int weig;
  const int kfeetChan = 12;
  const float kmChan = 0.0254;
  const float kweigChan = 1/2.2;

  cout << "Input your feet hight-->";
  cin >> feet;
  cout << endl;
  cout << "Then input your inch hight please-->";
  cin >> inch;
  cout << endl;
  inch = inch + feet*kfeetChan;
  cout << "OK GOT YOUR HEIGHT IS " << inch << " FEET";
  float highM = inch*kmChan;
  cout << endl;
  cout << "Now input your weight useing pound-->";
  cin >> weig;
  cout << endl;
  cout << "OK GOT YOUR WEIGHT IS " << weig <<" POUND";
  cout << endl;
  weig = weig * kweigChan;
  cout << "YOUR BMI IS " << weig/(highM*highM);
  /*********************************************************************************************/

  const float kchang = 60;  //不要在这里取1/60这样程序的精度就变的更小了
  float degerss;
  float minu;
  float secend;
  float endnum;
  cout << "Enter a latitude in degrees,minutes,and seconds: " << endl;
  cout << "First,enter the degrees :";
  cin >> degerss;
  cout << endl;
  cout << "Next enter the minutes of arc : ";
  cin >> minu;
  cout << endl;
  cout << "Finally,enter the sencend of arc :";
  cin >> secend;
  cout << endl;

  endnum = degerss + minu/kchang + secend/(kchang*kchang);
  cout << degerss << "degress," << minu <<"minutes," << secend <<"secends = " << endnum <<"  degrees";

  return 0;
  
}