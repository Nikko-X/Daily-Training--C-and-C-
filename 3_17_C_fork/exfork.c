#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void exit_status(pid_t p,int state);
int main(int argc,char **argv[])
{
    pid_t pid,spid;
    int s_son = -1;

    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return -1;
    }
    else if(0 == pid)   //如果是子进程，成功返回0
    {
        printf("子进程pid: %d \n",getpid());
        sleep(1);
        //exit(EXIT_FAILURE);
        exit(EXIT_SUCCESS);
    }
    else if(pid > 0)    //父进程返回子进程pid
    {
        printf("父进程pid: %d\n",getpid());
        spid = wait(&s_son);    //前面定义了s_son = -1，表示等待任意子进程退出
        exit_status(spid,WEXITSTATUS(s_son));   //得到退出状态
    }
    return 0;
}

void exit_status(pid_t p,int state)
{
    switch (state)
    {
    case 0:
        printf("子进程--%d--退出状态：EXIT_SUCCESS\n",p);
        break;
    case 1:
        printf("子进程--%d--退出状态：EXIT_FAILURE\n",p);
        break;
    default:
        printf("other\n");
        break;
    }
}