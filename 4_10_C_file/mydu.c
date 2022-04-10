/* du 可以读取 传入文件或者传入目录 下的文件所占空间大小*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static __ino64_t mydu(const char* path) //防止数据溢出采用ll型数据
{
    struct stat staters;
    if(lstat(path, &staters) < 0)   //获取文件属性
    {
        perror("lstat()");
        exit(1);
    }

    if(!S_ISDIR(staters.st_mode))       //path文件是非目录文件
        return staters.st_blocks/2;     //block除2就是文件大小，单位 K     
    else                                //path为目录文件
    {
        
    }                
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
       fprintf(stderr, "Usagee...\n");
       exit(1);
    }
    
    printf ("%lld\n",mydu(argv[1]));

    exit(0);
}