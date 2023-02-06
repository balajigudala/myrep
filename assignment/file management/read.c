// reading the values and storing int the buffer and printfing buffer..............

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{
	char buf[100];
	int fd,ret;
	fd=open("open.c",O_RDONLY);
//	printf("%d\n",fd);
        if(fd<0)
	{
		printf("failed to open the file \n");
		exit(1);
	}
	ret=read(fd,buf,10);
	//printf("%d\n",ret);
	buf[ret]='/0';
	printf("%s\n",buf);
	ret=read(fd,buf,99);
	printf("%d\n",ret);
	//printf("%s\n",buf);
        close(fd);
}


