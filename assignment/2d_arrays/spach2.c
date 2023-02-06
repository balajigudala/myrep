#include<stdio.h>
#include<stdlib.h>
void main()
{
	int r,e;
	printf("enter the number of rows\n");
	scanf("%d",&r);
	printf("enter the number of coloms\n");
	scanf("%d",&e);

	//int arr[r][e];

	int(*arr)[e]=(int(*)[])malloc(r* sizeof(int));        //.....................dynamically allocation of memory using pointer to array.............
	int(*arr1)[e]=(int(*)[])malloc(r* sizeof(int));        //....................dynamically allocation of memory using pointer to array of arr2.......... 
	int i,j;
	int k=0,count=0;

	printf("enter the elements\n");

	for(i=0;i<r;i++)
	{
		for(j=0;j<e;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0)
				count++;
		}
	}

	//int arr1[count][3];
//	int(*arr2)[e]=(int(*)[])realloc(arr1,count*3*sizeof(int));
         int arr2[count][3];

	for(i=0;i<r;i++)
	{
		for(j=0;j<e;j++)
		{
			if(arr[i][j]!=0)
			{
				arr2[k][0]=i;
				arr2[k][1]=j;
				arr2[k][2]=arr[i][j];
				k++;
			}
		}
	}
	printf("\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",arr2[i][j]);
		}
		printf("\n");
	}


}
