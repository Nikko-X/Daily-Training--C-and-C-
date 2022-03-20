#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#define BUFFSIZE 120
//char addr;
//char buf[BUFFSIZE];


size_t myGetline(FILE *mStream,char *mAddr,int mSize)
{
    while (1)
    {
        fgets(mAddr,BUFFSIZE,mStream) ;
        mlock(&mAddr, 120);
        mSize = 120;
        if(fgets(mAddr,BUFFSIZE,mStream) == NULL)
            break;
    } 
    return 1;
}
int main(int argc,char **argv)
{
    FILE *pd;
    int linesize = 0;
    char *linebuf = NULL; 
    if(argc < 2)
    {
        printf("Erro Usage:");
        return 1;
    }
    pd = fopen(argv[1],"r");
    if (pd == NULL)
    {
        printf("open erro\n");
    }
    myGetline(pd,linebuf,linesize);
    fclose(pd);
    printf("%ld\n",strlen(linebuf));
    printf("%d\n",linesize);
    return 0;
}