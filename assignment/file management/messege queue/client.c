#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	int msgid;
	msgid=msgget(KEY,0);
	printf("return value:%d\n",msgid);
	messege.msgtype=MSG_TYPE;
	messege.pid=getpid();
	strcpy(messege.buff,"sheshu reddy");
	msgsnd(msgid,&messege,sizeof(messege),0);
	printf("data received\n");
	printf("%s\n",messege.buff);
}


