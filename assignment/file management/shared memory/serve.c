#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define KEY 0x1998860

void main()
{
	char *ptr;
	int shmid,ret;
	shmid=shmget(KEY,512,IPC_CREAT|0660);// shmget is used to create shared memory size depends on second arg.
	if(shmid<0)
	{
		printf("failed\n");
		exit(1);
	}
	//printf("%d\n",shmid);
	ptr=shmat(shmid,NULL,0);//it is used to atrtach the shared memory region to our current process
	ptr[0]='\0';
	while(ptr[0]=='\0');
	//	sleep(1);
	printf("%s\n",ptr);
	//ret=shmdt(ptr);
	printf("%d\n",ret);
	 strcpy(ptr,"sheshu");
	 //printf("%s",ptr+256);
	 printf("Sleep\n");
	 sleep(5);
        ret=shmdt(ptr);
        printf("%d\n",ret);

}


