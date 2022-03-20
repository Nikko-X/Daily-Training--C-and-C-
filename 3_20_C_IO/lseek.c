/*实现copy函数*/

#include<stdio.h>
#include<stdlib.h>
#define BUFFSIZE 1024
int main(int argc,char **argv)
{
    FILE *fp;
    char buf[BUFFSIZE];
    if(argc < 2)
    {
        fprintf(stderr,"Usage:%s <src_file> <dest_file>",argv[0]);
        exit(1);
    }

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    fseek(fp,0,SEEK_END);   //定位到文件末尾处
    printf("%ld \n",ftell(fp));    //打印出当前指针位置
                                   //因为前面已经定位到文件末尾，所以可以知道打印出的值就是文件长度
    fclose(fp);
    exit(0);
}