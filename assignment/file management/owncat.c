#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<unistd.h>

void main(int argc,int *argv[])
{
	int fd,rd;
	char buf[100];
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		printf("failed to open\n");
		exit(1);
	}
	while(rd=read(fd,buf,99))
	{
		if(rd<0)
		{
			printf("failed to read\n");
			exit(2);
		}
		buf[rd]='\0';
		printf("%s\n",buf);
	}
}

