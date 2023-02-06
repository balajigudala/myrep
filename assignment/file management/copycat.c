#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main(int argc,int *argv[])
{
	int fd,fd1,ret;
	char buf[100];
	//fd=open(argv[1],O_RDONLY);
	fd=open("open.c",O_RDONLY);
	if(fd<0)
	{
		printf("failed toopen\n");
		exit(1);
	}
	printf("%d\n",fd);
	//fd1=open(argv[2],O_CREAT|O_RDWR|O_TRUNC,0777);
	fd1=open("reddy.c",O_CREAT|O_RDWR|O_TRUNC,0777);
	if(fd1<0)
	{
		printf("failed to create\n");
		exit(2);
	}

	while(ret=read(fd,buf,99))
	{
		if(ret<0)
		{
			printf("failed to read\n");
			exit(3);
		}
		int ret1=write(fd1,buf,ret);
	}
	printf("%s\n",buf);
	close(fd);
	close(fd1);
}



