#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
/*制造一个5G的空洞文件，空洞文件利用CP进行拷贝的时候是不占空间的*/
int main(int argc, char **argv)
{
	int fd;
	if(argc < 2)
	{
		fprintf(stderr,"Usage...\n");
		exit(1);
	}
	
	fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0600);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}

	lseek(fd,5LL*1024LL*1024LL*1024LL-1LL,SEEK_SET);	//必须每个都加上LL,不然默认是整型会产生溢出
	write(fd,"",1);	//如果不写这个字节，这个文件是不会占用系统空间的
	close(fd);

	exit(0);
}
