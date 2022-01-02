#include <stdio.h>

struct Stu
{
    char name[20];
    short age;
    char tele[11];
    char sex[5];
};

typedef struct Stu1     //利用typedef 方便使用结构体
{
    char name[20];
    short age;
    char tele[11];
    char sex[5];
}Stu1;      //后面直接用Stu1 就可以定义结构体变量了，不需要加struct 方便程序阅读

int main()
{
    struct Stu s;    //创建结构体变量
    Stu1 s2;
   
    
    return 0;
}