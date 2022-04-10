/*使用glob函数来解析目录*/
#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>

//#define PAT  "/etc/a*.conf" //宏定义一个需要解析的路经（这里是etc目录下所有以a开头的文件）
#define PAT  "/etc/*"   //etc下所有文件，必须加 *

static int errfunc(const char* errpath, int errno)
{
    puts(errpath);
    fprintf(stderr, "ERROR MSG: %s\n", strerror(errno)); //向标准出错上报错
    return 0;
}

int main(int argc, char** argv)
{
    glob_t globres;
    int err = glob(PAT, 0, NULL, &globres); //需要解析的路经，参数，报错的原因(需要定义一个函数在上面，可以写NULL),读取参数存放位置（是一个结构体）
    if(err)
    {
        printf("ERROR CODE: %d\n", err);
        exit(1);    //进程出错没必要往下进行，就不用return了
    }
    for (size_t i = 0; i < globres.gl_pathc; i++) 
    {
        puts(globres.gl_pathv[i]);  //这里的gl_pathc与gl_pathv和主函数的argc,argv相似
    }

    globfree(&globres); //释放地址

    exit(0);
}
