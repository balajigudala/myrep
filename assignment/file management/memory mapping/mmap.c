#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main()
{
	struct stat buff;
	int fd;
	char *ptr;
	fd=open("bitwise.c",O_RDWR);
	if(fd<0)
	{
		printf("failed to open file\n");
		exit(1);
	}
	fstat(fd,&buff);
	ptr=mmap(NULL,buff.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	write(1,ptr,buff.st_size);
	munmap(ptr,buff.st_size);
}

