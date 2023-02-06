
//--------------------- INVOKING NEW THREAD AND THREAD TERMINATION -----------------------

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *mythread(void *ptr)
{
	printf("new thread is invoked\n");
	int i;
	//	printf("mythread is invoked\n");
	for(i=0;i<=*(int *)ptr;i++)
	{
		sleep(1);
		printf("%d\n",i);
	}
	printf("new thread execution is completed\n");
}

void main()
{
	pthread_t ti;
	int i,ret,loop=100;
	//sleep(5);
	ret=pthread_create(&ti,0,mythread,&loop);
//	sleep(5);
//	exit(0);
      pthread_exit(&ret);
	printf("main thread [or] main function is terminated\n");
}
