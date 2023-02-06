#include<stdio.h>
void second_smallest();
void main()
{
	second_smallest();
}


void second_smallest()
{
	int arr[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("enter a input\n");
		scanf("%d",&arr[i]);
	}

	int j,k;
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[i]>arr[j])
				arr[i];
			else
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}


	for(i=4;i>=0;i--)
	{
		if(i==0)
		{
			printf("all are same values\n");
			return;
		}
		if(arr[4]==arr[i]);
		else
		{
			printf("%d\n",arr[i]);
			return;
		}
	}
}



/*	int i,min,n,smin,max=0;
	printf("enter the array elements\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
	printf("enter a value\n");
	scanf("%d",&arr[i]);
	}


	for(i=0;i<n;i++)
	{
	if (arr[i]>max)
	{
	max=arr[i];

	}
	min=max;
	smin=max;
	for(i=0;i<n;i++)
	{
	if(arr[i]<=min)
	{
	smin=min;
	min=arr[i];
	}
	else if(arr[i]<smin)
	smin=arr[i];
	}
	printf("second min is %d\n",smin);
	}
	}*/

