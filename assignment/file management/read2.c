#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


void main()
{
	int fd1,fd2,ret1,ret2;
	char buf1[10],buf2[10];

	fd1=open("open.c",O_RDONLY);
	ret1=read(fd1,buf1,9);
	printf("%d-%d\n",fd1,ret1);
	buf1[ret1]='\0';
	printf("%s\n",buf1);

	fd2=open("open.c",O_RDONLY);
	ret2=read(fd2,buf2,5);
	printf("%d-%d\n",fd2,ret2);
	buf2[ret2]='\0';
	printf("%s\n",buf2);

	close(fd1);
	close(fd2);
}

