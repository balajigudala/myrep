#include<stdio.h>
main()
{
	int arr[10]={1,2,3,4,5,1,6,7,9,5};
	
	int c=0,i,j;
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]==arr[j])
			{
				c++;
			}
		}

	}
	if(c>0)
	{
	for(i=0;i<10;i++)
	{
				printf("%d\n",arr[j]);
		}
	}
}
