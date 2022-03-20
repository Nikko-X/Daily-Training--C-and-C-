#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*fseek()、ftell()例*/
/*
int main(int argc,char **argv)
{
    FILE *fp;
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
    printf("%ld",ftell(fp));    //打印出当前指针位置
                                //因为前面已经定位到文件末尾，所以可以知道打印出的值就是文件长度
    fclose(fp);
    exit(0);
}
*/

/*getline()例*/
int main(int argc,char **argv)
{
    FILE *fp;
    size_t linesize = 0;
    char *linebuf = NULL;   //这俩句一定要初始化，很重要
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

    while (1)
    {
        if(getline(&linebuf, &linesize, fp) < 0)    //每一行指针的位置，每一行空间大小，要读的流
            break;
        printf("%ld\n",strlen(linebuf));
        printf("%ld\n",linesize);
    }
    
    
    fclose(fp);
    exit(0);
}