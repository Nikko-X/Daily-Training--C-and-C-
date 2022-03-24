#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char **argv[])
{
    //fflush(stdout); //  刷新一下缓冲区 让它马上输出.  在printf 之后调用它,就会马上输出了.
    //setvbuf(stdout,NULL,_IONBF,0); //如果你嫌上个方法麻烦, 就使用这个函数. 直接将缓冲区禁止了. 它就直接输出了.
    pid_t pid;
    int i;
    /*创建进程成功 在父进程中会返回子进程的PID 在子进程中会返回 0*/
    for(i=0;i<2;i++)
    {
        pid = fork();   //进程创建后会从这句后面开始执行
        /*所以第一次会打印2个进程号，第二次进入循环后就有2个进程了
        *第二次循环他们又各自创建一个进程，所以第二次会打印4个进程号
        *所以总体而言会打印6个进程号，但有2个是重复的
        */
        if(-1 == pid)
        {
            printf("Fork Erro!");
            return -1;
        }

        if(pid > 0)
        {
            printf("进程: %d \n",getpid());
        }
        else if(0 == pid)
        {
            printf("进程: %d \n",getpid());
        }
    }

    return 0;
}