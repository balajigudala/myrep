#include<stdio.h>
#include<pthread.h>
//#include<stdio.h>

int glob=0;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
void *thread_fun1(void *arg);
void *thread_fun2(void *arg);

void main()
{
	void *ret;
	pthread_t t1,t2;
	int res,loop=100,loop2=200;
	pthread_create(&t1,0,thread_fun1,&loop);
	pthread_create(&t2,0,thread_fun2,&loop2);
	// blocking calls...if blocking is done cpu register's data is stored in [ context area of pcb ]
	pthread_join(t1,&ret);
	pthread_join(t2,&ret);
	printf("%d\n",glob);
}

void *thread_fun1(void *arg)
{
	int loop,i,local;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
		printf("firstthread");
		printf("%d\t",i);
		pthread_mutex_lock(&mtx);
		local=glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mtx);
	}
}

void *thread_fun2(void *arg)
{
	int loop,i,local;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
		printf("\tsecond thread ");
		printf("%d\t",i);
		pthread_mutex_lock(&mtx);
		local=glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mtx);
	}
}
