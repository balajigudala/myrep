//     SERVER 

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

void main()
{
	while(1)
	{
	int ret,fd;
	char wbuf[20];
	char rbuf[20];
	fd=open("servfifo",O_RDONLY);
	
	if(fd<0)
	{
		ret=mkfifo("servfifo",0660);
		if(ret<0)
		{
			printf("failed to create\n");
			exit(1);
		}
		fd=open("servfifo",O_RDONLY);
		
		if(fd<0)
		{
			printf("failed to open\n");
			exit(2);
		}
		printf("ffffff\n");
	}
	ret=read(fd,rbuf,20);
	if(ret<0)
	{
		printf("failed to read\n");
		exit(3);
	}
	ret=write(1,rbuf,ret);
	if(ret<0)
	{
		printf("failed to write\n");
		exit(4);
	}
	
 fd=open("serv1fifo",O_WRONLY);
        if(fd<0)
        {
                printf("failed to open\n");
                exit(1);
        }
        printf("enter the content\n");
	scanf("%[^\n]s",wbuf);
        ret=write(fd,wbuf,strlen(wbuf));
	printf("\n");
        if(ret<0)
        {
                printf("failed to write\n");
                exit(2);
        }
close(fd);
}
}

