#include<stdio.h>
#include<stdio_ext.h>
#include<signal.h>
#include<unistd.h>

void isr(int n)
{
	printf("%d",n);
	signal(2,SIG_DFL);
}




int main()
{
	pid_t  pid;

	int i=0,ret=0;
	printf("Pid:%d\n",getpid());
	signal(2,isr);
	ret=pause();
	printf("The returned value:%d\n",ret);
	while(i<=5)
	{
		printf("The output:%d\n",i);
		i++;
	}
}






