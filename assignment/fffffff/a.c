#include<stdio.h>

int main()
{
	int arr[][2]={{1,2},{4,5}};
/*	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}*/
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("Enter the element of %d\n",arr[i][j]);
			//scanf("%d",&arr[i][j]);
		}
		
	}
}
