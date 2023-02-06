//------------------------CREATING OUR OWN COPY COMMAND--------------------

#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

void main()
{
	struct stat buff;
	int fd,fd1,ft;
	char *ptr,*ptr1;
	fd=open("bitwise.c",O_RDONLY);
	if(fd<0)
	{
		printf("failed to open file\n");
		exit(1);
	}
	fstat(fd,&buff);
	ptr=mmap(NULL,buff.st_size,PROT_READ,MAP_SHARED,fd,0);

	fd1=open("new.c",O_CREAT|O_RDWR,0660);
	if(fd1<0)
	{
		printf("failed to create file\n");
		exit(2);
	}

	ft=ftruncate(fd1,buff.st_size);

	fstat(fd1,&buff);
	
	ptr1=mmap(NULL,buff.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
	memcpy(ptr1,ptr,buff.st_size);

	munmap(ptr,buff.st_size);
	munmap(ptr1,buff.st_size);



}

