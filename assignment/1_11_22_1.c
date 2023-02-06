#include<stdio.h>
#include<stdlib.h>
//#define NM 5
void push(int *ptr,int n);
void pop();
void display(int *ptr,int n);
void search(int *ptr,int n);
int i=-1,k=-1;
main()
{
	int n,opt;
	int arr[5];
	while(1)
	{

		printf("menu\n0.exit\n1.push\n2.pop\n3.display\n4.search\nenter ur option\n");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("enter the inputs\n");
			       scanf("%d",&n);
			       push(arr,n);
			       break;
			case 2:pop();
			       break;
			case 3:display(arr,5);
			       break;
			case 4:printf("enter the input\n");
			       scanf("%d",&n);
			       search(arr,5);
			       break;
		}
	}
}



void push(int *ptr,int n)
{
	if(i==4)
	{
		printf("stack is full\n");
		return;
	}


	i++;
	ptr[i]=n;

}




void pop()
{
	if(i==-1)
	{
		printf("stack is empty\n");
		return;
	}
	i--;
}






void display(int *ptr,int n)
{
	int j;
	if(i==-1)
	{
		printf("stack is mt\n");
		return;
	}
	for(j=0;j<=i;j++)
	{
		printf("%d\n",ptr[j]);
	}
}



void search(int *ptr,int n)
{
	int d,p;
	printf("enter the value to be searched\n");
	scanf("%d",&d);
	for(p=0;p<5;p++)
	{
		if(ptr[p]==d)
		{
			printf("%d valid data\nindex is:%d\n",d,p);
			return;
		}

	}
}










