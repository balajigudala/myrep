#include<stdio.h>
int main()
{
	int i,j;
	int arr[5][5]={8,0,3,0,3,0,4,0,3,4,2,0,4,0,4,0,2,7,0,0,56,0,0,0,7};

	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			if(arr[i][j]>0)
			{
			 printf("%d-%d-%d\n",i,j, arr[i][j]);
			}
		}
	 
	}

}

