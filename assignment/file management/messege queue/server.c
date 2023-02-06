//----------messege queue;---------[server code]-------------------

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#define KEY 0X1998860
#define MSG_TYPE 1
struct msg
{

	long msgtype;
	long pid;
	char buff[100];
}messege;

void main()
{
	char buff[100];
	int msgid;
	msgid=msgget(KEY,IPC_CREAT|0604);
	printf("retrun value:%d\n",msgid);
	msgrcv(msgid,&messege,sizeof(messege),MSG_TYPE,0);
	printf("the messege: %s\n",messege.buff);
}

