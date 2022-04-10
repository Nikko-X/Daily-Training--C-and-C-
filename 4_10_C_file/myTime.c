/*使用getopt 函数编辑命令行参数顺序*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  
#include <string.h>
/*
* -y: year
* -m: mouth
* -d: day
* -H: hour
* -M: minute
* -S: second
*/

#define TIMESTRSIZE 1024
#define FMTSTRSIZE 1024
int main(int argc, char** argv)
{
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];
    int c;
    FILE *fp = stdout;
    char fmtstr[FMTSTRSIZE];
    fmtstr[0] = '\0';

    stamp = time(NULL);
    tm = localtime(&stamp);

    while (1)
    {
        c = getopt(argc, argv, "-H:MSy:md");   //查找 命令行输入的参数，后面的字符串是否包含 在字符串加上：后，可实现选择 
                                              //在发现对应的字符后 *optarg 会自动指向下一个字符
                                              //在该字符串前加上一个 - ，当输入不属于该字符串的内容时，会返回 1
        if(c<0)
            break;
        switch (c)
        {
        case 1:
            if(fp == stdout)    //以第一个输入的文件路经为准，后面再输入就不管
            {
                fp = fopen(argv[optind - 1], "w");
                if(fp == NULL)
                {
                    perror("fopen()");
                    fp = stdout;
                }
            }
            break;
        case 'H':
            if (strcmp(optarg,"12") == 0)
                strncat(fmtstr, "%I(%P) ", FMTSTRSIZE);  //FMTSTR...=1024 会产生一个警告,后面的一样会出现
            else if(strcmp(optarg,"24") == 0)
                strncat(fmtstr, "%H ", FMTSTRSIZE);
            else
                fprintf(stderr,"Invalid argument");
            break;
        case 'M':
            strncat(fmtstr, "%M ", FMTSTRSIZE);  //将第二个字符串 附加到fmtstr中，字符串加空格，输出到终端的数字也会带空格。
            break;
        case 'S':
            strncat(fmtstr, "%S ", FMTSTRSIZE);
            break;
        case 'y':
            if (strcmp(optarg,"2") == 0)
                strncat(fmtstr, "%y ", FMTSTRSIZE);
            else if (strcmp(optarg,"4") == 0)
                strncat(fmtstr, "%Y ", FMTSTRSIZE);
            else
                fprintf(stderr,"Invalid argument");
            break;
        case 'm':
            strncat(fmtstr, "%m ", FMTSTRSIZE);
            break;
        case 'd':
            strncat(fmtstr, "%d ", FMTSTRSIZE);
            break;
        
        default:
            break;
        }
    }
    strncat(fmtstr, "\n", FMTSTRSIZE);
    strftime(timestr, TIMESTRSIZE, fmtstr, tm);
    fputs(timestr,fp);

    if(fp != stdout)
        fclose(fp);
    return 0;
}