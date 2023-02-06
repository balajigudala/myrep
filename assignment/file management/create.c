#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
	int fd,nfd,ret;
	char buf[20];
	fd=open("open.c",O_RDWR);
	ret=read(fd,buf,5);
	buf[ret]='\0';
	printf("%s\n",buf);
	nfd=creat("open.txt",0664);
	ret=write(nfd,"hi",strlen("hi"));
	ret=read(fd,buf,5);
	ret=write(fd,"hello",5);
}
