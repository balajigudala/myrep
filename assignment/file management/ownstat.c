#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
//#include<stdio_ext.h>

void main(int argc, char *argv[])
{
	if(argc<1)
	{
		printf("incorrect syntax\n");
		exit(10);
	}
	
	struct stat var;
	int fd;
	fd=stat(argv[1],&var);
	if(fd<0)
	{
		printf("failed to open\n");
		exit(1);
	}

	printf("device name  : %ld\n",var.st_dev);
	printf("inode no     : %ld\n",var.st_ino);
	printf("file mode    : %d\n",var.st_mode);
	printf("link count   : %ld\n",var.st_nlink);
	printf("user id      : %d\n",var.st_uid);
	printf("group id     : %d\n",var.st_gid);
	printf("size of file : %ld\n",var.st_size);
	close(fd);
}


