#include<stdio.h>
#include<pthread.h>
//#include<stdio.h>

//int glob=0;
int i=0;
void *thread_fun1(void *arg);
void *thread_fun2(void *arg);

void main()
{
        void *ret;
        pthread_t t1,t2;
        int res,loop=2000;
        pthread_create(&t1,0,thread_fun1,&loop);
        pthread_create(&t2,0,thread_fun2,&loop);
        // blocking calls...if blocking is done cpu register's data is stored in [ context area of pcb ]
        pthread_join(t1,&ret);
        pthread_join(t2,&ret);
        printf("%d\n",i);
}

void *thread_fun1(void *arg)
{
        int loop,i,local;
        loop=*(int*)arg;
        for(i=0;i<loop;i++)
        {
                if(i%2==0)
		{
			//printf("EVEN\n");
			printf("num : %d\n--------- thread id:% lu\n",i,pthread_self());
			sleep(2);
		}

        }
}

void *thread_fun2(void *arg)
{
        int loop,i,local;
        loop=*(int*)arg;
        for(i=0;i<loop;i++)
        {
                if(i%2!=0)
		{
			//printf("ODD\n");
			printf("num : %d\n--------- thread id:% lu\n",i,pthread_self());
			sleep(2);
		}
        }
}

