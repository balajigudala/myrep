#include<stdio.h>
void main()
{
	int n;
	printf("enter no. of elements\n");
	scanf("%d",&n);
	int arr[n];
	int i,j,target=25;
	int count=0;
	for(i=0;i<n;i++)
	{
		printf("enter the element arr[i]:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]+arr[j]==target)
			{
				count++;
			
				printf("%d + %d =%d\n",arr[i],arr[j],target);

			}
		}
	}

	printf("no.of possibilities: %d\n",count);
}
