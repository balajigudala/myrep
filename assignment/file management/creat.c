#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buff[100];
	int fd,ret;
	fd=creat("seshu.txt",0777);
	if(fd < 0)
	{
		printf("The create is failed\n");
		exit(1);
	}
	printf("Created fd:%d\n",fd);
	scanf("%[^\n]",&buff);
	ret=write(fd,buff,99);
	if(ret < 0)
	{
		printf("Write is failed\n");
		exit(1);
	}
	close(fd);
	fd=open("seshu.txt",O_TRUNC);



	


}

