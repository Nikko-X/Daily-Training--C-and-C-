/*
*学习目录IO的用法，与文件IO不同
*opendir,mkdir,readdir,closedir
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
  int ret;
  DIR *dp;

  if(argc != 2)
  {
    printf("Usage %s <name file>\n",argv[0]);
    return -1;
  }
  /*ret = mkdir(argv[1],0666);
  if(ret < 0)
  {
    printf("mkdir is erro\n");
    return -1;
  }
  if(ret = 0)
  {
    printf("mkdir is ok");
  }*/

  dp = opendir(argv[1]);
  if(dp != NULL)
  {
    printf("opendir is ok\n");
  }
  close(dp);
  
  return 0;
}