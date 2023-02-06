#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buff[100];
	char buf[100];
	int fd,ret;
	fd=creat("seshu.txt",0777);    // create a file
	if(fd < 0)
	{
		printf("The create is failed\n");
		exit(1);
	}
	printf("Created fd:%d\n",fd);
	scanf("%[^\n]",&buff);           // reading input........
	fd=open("seshu.txt",O_RDWR);     //........opening that file under read and write mode.......
	ret=write(fd,buff,strlen(buff));  // writing something using write()...
	if(ret < 0)
	{
		printf("Write is failed\n");
		exit(1);
	}
	ret=lseek(fd,0,SEEK_SET);  //.... setting the cursor position....
	printf("Lseek:%d\n",ret);
	ret=read(fd,buf,99);       //---reading the input of that file------
	printf("Read:%d\n",ret);
		buf[ret]='\0';
	printf("The out:%s\n",buf);






}

