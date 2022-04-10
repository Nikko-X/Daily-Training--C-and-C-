#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int ftype(const char *fname)
{
    struct stat staters;
    if(stat(fname, &staters) < 0)
    {
        perror("stat error: ");
        exit(1);
    }

    if(S_ISREG(staters.st_mode))
        return '-';
    else if(S_ISDIR(staters.st_mode))
        return 'd';
    else if(S_ISSOCK(staters.st_mode))
        return 's';
    else
        return '?';
}
int main(int argc, char** argv)
{
    if(argc < 2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    printf("%c\n",ftype(argv[1]));
    exit(0);
}