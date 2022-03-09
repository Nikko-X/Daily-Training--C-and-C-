#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char **argv[])  
{
  //argc表示命令行中参数的个数
  //argv 表示的是吗命令行中的参数，参数原则上是没有上限的

  int fd_a;
  int fd_b;
  char buf[32] = {0};
  char bufToB[32] = {0};
  char *bufWrite = "\nHello Welcome!";
  int ret;
/******************************************************************************************************************************************/
  fd_a = open("a.txt", O_CREAT|O_RDWR,0666); //有O_CREAT才需要第三个参数
                                            //这里给的权限要与 umask 里的值按位与 最终得出的是0644  即rw- r-- r-- 其中 可读 4 可写 2 可执行 1
  if(fd_a == -1)
  {
    printf("open is erro\n");
  }else
  {
    printf("fd_a is %d\n",fd_a);  //打印结果是 3 因为0、1、2分别对应标注输入，标准输出、标准出错
    //close(fd);  //释放文件描述符
  }

/********************************************************************************************************************************************/
  ret = read(fd_a,buf,sizeof(buf)); //read函数
  if(ret == -1)
  {
    printf("read erro!\n");
  }else
  {
    printf("buf is %s\n",buf);
    printf("ret is %d\n",ret);
  }
  write(fd_a,bufWrite,strlen(bufWrite)); //往fd_a上写字符串里的内容
/*******************************************************************************************************************************************/
  
  close(fd_a);  //释放文件描述符
  fd_a = open("a.txt", O_CREAT|O_RDWR,0666); //不重新打开读取不到值（可能指针已经指向文件末尾）
  //lseek(fd_a,0,SEEK_SET);   //利用lseek 函数将指针移到文件开头的位置，就不用重新打开了
  fd_b = open("b.txt", O_CREAT|O_RDWR,0666);
  if(fd_b == -1)
  {
    printf("open b.text is erro\n");
  }

  ret = read(fd_a,bufToB,sizeof(bufToB)); //read函数
  if(ret == -1)
  {
    printf("read fd_a to buff erro!\n");
  }
  write(fd_b,bufToB,strlen(bufToB)); //将a中内容拷贝到b里面，这里要用strlen不能用sizeof,因为这个寄存器不一定存满

  close(fd_a);  //释放文件描述符
  close(fd_b);

  return 0;
}