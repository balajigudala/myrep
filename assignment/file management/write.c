//  WRITE SYSTEM CALL () .............
// .... in this systen call what even we will write in write() it will be reflected on original file...
//... when we use read() the cursor will jump to last letter of the program ...then after when we perform write() the content in the original file is replaced from where the cursor stops.........

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int fd,ret;
	char buf[30]="naga datta dharmendra";
	char rbuf[30];
	fd=open("open.c",O_RDWR);
	printf("%d\n",fd);
	if(fd<0)
	{
		printf("failed to open the file\n");
		exit(1);
	}

	ret=write(fd,buf,strlen(buf));
	ret=read(fd,rbuf,30);
	rbuf[ret]='\0';
	printf("%s\n",rbuf);
	close(fd);
}


