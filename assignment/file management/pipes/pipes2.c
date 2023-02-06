#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


void main()
{
        pid_t pid;
        int fd[2],fd2[2],ret,ret2;
        char buf[100],char buf2[100];
        ret=pipe(fd);
        ret2=pipe(fd2);
        pid=fork();
        if(pid<0)
        {
                printf("failed to create child\n");
                exit(0);
        }
        else if(pid>0)
        {
                printf("parent process--------------\n");
                close(fd[0]);
                ret=write(fd[1],"sheshu reddy",strlen("sheshu reddy"));
                printf("%d\n",ret);
                close(fd[1]);
                exit(0);
        }
        else
        {
                printf("child process---------------\n");
                close(fd[1]);
                ret=read(fd[0],buf,100);
                printf("%d\n",ret);
                write(1,buf,ret);
                printf("%d\n",ret);
                close(fd[0]);
                exit(1);
        }
}

