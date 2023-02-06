// accessing the data of 20 bytess using void pointer in it.

#include<stdio.h>
#include<stdlib.h>
int readinput(void *ptr,int n);
int displayinput(void *ptr,int n);
void biggest(void *ptr,int n);
void sec_biggest(void *ptr,int n);
void binary_conversion(void *ptr,int n);
void ascending(void *ptr,int n);
void main(void)
{
	int n,opt;
	void *ptr;
	ptr=(void*)calloc(5,sizeof(int));
	if(ptr==NULL)
	{
		printf("failed to allocate memory in heap\n");
		exit(1);
	}

	while(1)
	{

		printf("menu\n0.exit\n1.read\n2.display\n3.biggest\n4.second biggest\n5.binary conversion\n6.ascending order\nenter your option\n");
		scanf("%d",&opt);

		__fpurge(stdin);

		switch(opt)
		{




			case 0:exit(0);

			case 1:
			       readinput(ptr,5);
			       break;


			case 2:displayinput(ptr,5);
			       break;

			case 3:biggest(ptr,5);
			       break;

			case 4:sec_biggest(ptr,5);
			       break;


			case 5:
			       binary_conversion(ptr,5);
			       break;
                           case 6:
			       ascending(ptr,5);
			       break;

		}
	}
	free(ptr);
}


//       function definations********


int readinput(void *ptr,int n)
{
	int i=0;
	for(i=0;i<5;i++)                                            // ***** reading ******
	{
		printf("enter the input\n");
		scanf("%d",&((int *)ptr)[i]);
	}

}


int displayinput(void *ptr,int n)
{
	int i=0;
	for(i=0;i<5;i++)                                              // ***** displaying *******
	{
		printf("%d\n",((int *)ptr)[i]);
	}
}


void biggest(void *ptr,int n)
{
	int i,max=((int *)ptr)[0];
	for(i=0;i<5;i++)                                // ****** Biggst ******* 
	{
		if(max>((int *)ptr)[i])
			max;
		else
			max=((int *)ptr)[i];
	}
	printf("%d\n",max);
}


void sec_biggest(void *ptr,int n)
{
	int big=0,_2big=0,temp,i;                           // ****** second biggst ******
	for(i=0;i<5;i++)
	{
		

			temp=((int *)ptr)[i];
		if(((int *)ptr)[i]>big)
		{
			_2big=big;
			big=temp;
		}
		else if(temp>_2big)
			_2big=temp;
	}
	printf("%d",_2big);
}




void binary_conversion(void *ptr,int n)
{
	int temp,sum=0,i,num,j;                            // ***** binary conversion for the given no. of elements *******
	for(i=0;i<n;i++)
	{
		num=((int *)ptr)[i];
		sum=0;
		j=1;
		while(num>0)
		{
			temp=num%2;
			num=num/2;
			sum=sum+j*temp;
			j=j*10;
		}
		printf("%d-%d\n",((int *)ptr)[i],sum);
	}
}



void ascending(void *ptr,int n)
{
	int i,j,k;
	for(i=0;i<5;i++)
	{                                                                            // ******** ascending order of the given no. elements ******
		for(j=i+1;j<n;j++)
		{
			if(((int *)ptr)[i]>((int *)ptr)[j])
				(( int *)ptr)[i];
			

			else
			{
				int temp;
				temp=((int *)ptr)[i];
				((int *)ptr)[i]=((int *)ptr)[j];
				((int *)ptr)[j]=temp;
			}
		}
	}
	for(k=0;k<5;k++)
	{
		printf("%d\n",((int *)ptr)[k]);
	}

}

