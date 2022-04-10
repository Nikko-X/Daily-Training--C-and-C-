// Vector到Map的综合练习
//员工分组：招聘了10个员工，需要指派员工工作的部门
//员工信息：姓名、工资组成; 部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过mulmap进行信息的插入 key(部门编号) val(员工)
//分部门显示员工信息
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
using namespace std;

#define CeiHua 0
#define MeiShu 1
#define YanFa 2
//创建员工
class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker>& v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {

        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand()%10000 + 10000;   // 10000~19999 (rang()%a 表示 [0--10000)后面是开区间 )
        v.push_back(worker);
    }
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生一个随机的部门编号
        int depId = rand() % 3; //0 1 2随机数
        m.insert(make_pair(depId, *it));
    }
}

void shoeWorkerGroup(multimap<int, Worker>& m)
{
    cout << "策划部门：" << endl;
    map<int, Worker>::iterator pos = m.find(CeiHua);     //map里的值 是按key值排列的
    int count = m.count(CeiHua);    //统计策划部门总共人数
    int index = 0;
    for ( ;pos != m.end()&& index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
    }

    cout << "美术部门：" << endl;
    pos = m.find(MeiShu);     //map里的值 是按key值排列的
    count = m.count(MeiShu);    //统计策划部门总共人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
    }

    cout << "研发部门：" << endl;
    pos = m.find(YanFa);     //map里的值 是按key值排列的
    count = m.count(YanFa);    //统计策划部门总共人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));  //根据系统时间随机

    vector<Worker> vWorker;
    createWorker(vWorker);  //创建员工
    /*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++ )
    {
        cout << "姓名：" << it->m_Name << " " << "工资：" << it->m_Salary << endl;
    }*/
    multimap<int, Worker> mWorker;  //int为部门编号，后面为员工
    setGroup(vWorker, mWorker);  //进行员工分组
    //分组显示员工
    shoeWorkerGroup(mWorker);

}
