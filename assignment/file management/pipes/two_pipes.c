#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

void main()
{
	int fd[2],ret,ret1,i,stat=0,ret2,fd1;
	char buf[100];
	pid_t pid;
	char *msg="sheeeshuuu redddy";
	//printf("enter the string\n");
	//scanf("%[^\n]s",msg);
	ret=pipe(fd);
	ret1=pipe(fd);
	pid=fork();
	if(pid<0)
	{
		printf("failed to create child\n");
		exit(1);
	}
	else if(pid>0)
	{
		ret=write(fd[1],msg,strlen(msg));
		printf("parent process= %d\n",ret);
		close(fd[1]);
		ret1=read(fd[0],buf,99);
		buf[ret1]='\0';
		printf("after collecting child= %s\n",buf);
		close(fd[0]);
		exit(2);
	}
	else
	{
		ret=read(fd[0],buf,99);
		buf[ret]='\0';
		close(fd[0]);
		for(i=0;buf[i]!='\0';i++)
		{
			if ((buf[i]>='A')&&(buf[i]<='Z'))
				buf[i]=buf[i]+32;
			else if ((buf[i]>='a')&&(buf[i]<='z'))
				buf[i]=buf[i]-32;
		}
		ret1=write(fd[1],buf,strlen(buf));
		close(fd1);
	}
}
