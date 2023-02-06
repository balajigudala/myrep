#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("Parent pid: %d\n", getpid());
		printf("Parent-> Child Process pid: %d\n", pid);
		sleep(20);
		while(1)
		{
			printf("5555");
			sleep(1);
		}
	}
	else
	{
		printf("Child: %d\n", getpid());
		printf("Child: %d\n", getppid());
		printf("Child: %d\n", pid);
		sleep(50);
		while(1)
			printf("Hi");
	}
}
