/*钩子函数*/
#include <stdio.h>
#include <stdlib.h>

static void f1(void)
{
    puts("f1() is working!");
}

static void f2(void)
{
    puts("f2() is working!");
}

static void f3(void)
{
    puts("f3() is working!");
}

int main()
{
    puts("Begin!");
    atexit(f1);     //将3个函数挂到钩子上，注意被挂的函数必须无返回值和参数的，注意不是函数调用
    atexit(f2);     //是在正常语句执行完毕后执行，而且是f3先执行，即后挂上的会先执行
    atexit(f3);
    puts("End!");
    return 0;
}