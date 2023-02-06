#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	int fd,ret;
	fd=open("seshu.txt",O_RDONLY);
	if(fd<0)
	{
		printf("failed to open file\n");
		exit(10);
	}
	ret=dup2(fd,1);
	printf("welcome");
}

