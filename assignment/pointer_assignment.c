// accessing the data of 20 bytes with 5 elements in it in dynamic 

#include<stdio.h>
#include<stdlib.h>
int readinput(int *ptr,int n);
int displayinput(int *ptr,int n);
void biggest(int *ptr,int n);
void sec_biggest(int *ptr,int n);
void binary_conversion(int *ptr,int n);
void ascending(int *ptr,int n);
void main(void)
{
	int n,opt,*ptr;
	ptr=(int *)calloc(5,sizeof(int));
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
			       readinput(ptr,5);     //---------------------
			       break;


			case 2:displayinput(ptr,5);  //---------------------
			       break;                                                           /*   ------- FUNCTION INVOCATIONS :)    */

			case 3:biggest(ptr,5);       //---------------------
			       break;

			case 4:sec_biggest(ptr,5);    //--------------------
			       break;


			case 5:
			       binary_conversion(ptr,5);   //---------------
			       break;


			case 6:ascending(ptr,5);          //----------------
			       break; 
		} 
	}
	free(ptr);
}


// ******      function definations       ********


int readinput(int *ptr,int n)
{
	int i=0;
	for(i=0;i<5;i++)                                   // ******* READING *********
	{
		printf("enter the input\n");
		scanf("%d",&ptr[i]);
	}

}


int displayinput(int *ptr,int n)
{
	int i=0;                                        // ******* DISPLAYING **********
	for(i=0;i<5;i++)
	{
		printf("%d\n",ptr[i]);
	}
}


void biggest(int *ptr,int n)
{
	int i,max=ptr[0];                            // ********* BIGGEST ************
	for(i=0;i<5;i++)
	{
		if(max>ptr[i])
			max;
		else
			max=ptr[i];
	}
	printf("%d\n",max);
}


void sec_biggest(int *ptr,int n)
{
	int big=0,_2big=0,temp,i;
	for(i=0;i<5;i++)
	{                                              // ******** SECOND BIGGEST *****
		temp=ptr[i];
		if(ptr[i]>big)
		{
			_2big=big;
			big=temp;
		}
		else if(temp>_2big)
			_2big=temp;
	}
	printf("%d",_2big);
}




void binary_conversion(int *ptr,int n)
{                                                            // ******* BINARY CONVERSION OF THE GIVEN ELEMENTS ******
	int temp,sum=0,i,num,j;
	for(i=0;i<n;i++)
	{
		num=ptr[i];
		sum=0;
		j=1;
		while(num>0)
		{
			temp=num%2;
			num=num/2;
			sum=sum+j*temp;
			j=j*10;
		}
		printf("%d-%d\n",ptr[i],sum);
	}
}



void ascending(int *ptr,int n)
{
	int i,j,k;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<n;j++)                               // ******* ASCENDING ORDER OF THE GIVEN NO. OF ELEMENTS *******
		{
			if(ptr[i]>ptr[j])
				ptr[i];
			else
			{
				int temp;
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
	for(k=0;k<5;k++)
	{
		printf("%d\n",ptr[k]);
	}

}



