#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void main()
{
	int fd,fd1,fd2;
	fd=open("seshu.txt",O_RDWR);
	if(fd<0)
	{
		printf("failed to open file\n");
		exit(10);
	}

	printf("%d\n",fd);
	fd1=dup(1);
	printf("%d\n",fd1);
	write(1,"silicon",strlen("silicon"));
	write(fd1,"silicon",strlen("silicon"));
	fd2=dup(fd);
	printf("%d\n",fd2);
	close(fd);
	close(fd1);
	close(fd2);
}

