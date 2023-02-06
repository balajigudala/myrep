#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
 
void main()
{
	int fd,ret;
	char buf[5];
	fd=open("open.c",O_RDONLY);
	printf("%d\n",fd);
	if(fd<0)
	{
		printf("failed to open the file");
		exit(1);
	}
	while(ret=read(fd,buf,4))
	{
		if(ret<0)
		{
			printf("failed to reead file\n");
			exit(2);
		}
		buf[ret]='\0';
		printf("%s\n",buf);
	}
}
			

