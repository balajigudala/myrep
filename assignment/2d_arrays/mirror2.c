#include<stdio.h>
void main()
{
	int arr[3][3];
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("arr[i]:");
			scanf("%d",&arr[i][j]);
		}
	}
	printf("mirror matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=3-1;j>=0;j--)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
