#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<stdio_ext.h>
#include<stdlib.h>
void main()
{
	int k=0,ind=0,i,pid;
	int len,stat=0;
	char *point;
	char str[100];
	char *ptr[10];


	printf("Eneter the string\n");
	__fpurge(stdin);
	scanf("%[^\n]",str);
	len=strlen(str);
	for(i=0;i<=len;i++)
	{
		if(str[i]==' ' ||i==len)
		{
			str[i]='\0';
			ptr[ind]=str+k;
			k=i+1;
			ind++;
		}
	}
	/*for(i=0;i<ind;i++)
	  printf("%s",ptr[i]);*/
	//fork();
	pid=fork();
	if(pid<0)
	{
		printf("failed to create child\n");
		exit(1);
	}
	else if(pid>0)
	{
		wait(&stat);
		printf("parent run\n");
	}
	else
	{
		execvp(ptr[0],ptr);
	}

}









