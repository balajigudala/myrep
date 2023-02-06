#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
void main()
{
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("parents:%d\n",getpid());
		printf("parent:child process pid:%d\n",pid);
		sleep(10);
		while(1)
		{
			printf("111");
			sleep(1);
		}
	}
	else
	{
		printf("child:%d\n",getpid());
		printf("child:%d\n",getpid());
		printf("child:%d\n",pid);
		sleep(50);
		while(1)
		{
			printf("222");
		}
	}
}
