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
	shmid=shmget(KEY,512,0);
	ptr=shmat(shmid,NULL,0);
	strcpy(ptr,"hello");
	//ret=shmdt(ptr);
	//printf("%d\n",ret); 
	//ptr=shmat(shmid,NULL,0);//it is used to atrtach the shared memory region to our current process

	 //ptr = (ptr+256); 
		 ptr[0]='\0';

        while(ptr[0]=='\0');
                //sleep(1);
        printf("%s\n",ptr);
	printf("Sleep\n");
	sleep(2);
        ret=shmdt(ptr);
        printf("%d\n",ret);
}

