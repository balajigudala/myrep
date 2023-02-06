#include<stdio.h>
#define R1 3 
#define R2 3 
#define E1 3 
#define E2 4 


void multi(int r1,int r2, int e1,int e2,int (*ptr)[e1],int (*ptr1)[e2])       // here we should pass the two input matrix's no. of elements (or) column......pointer to array type...
{
	int i,j,k,sum=0;
	int res[r1][e2];
	for(i=0;i<r1;i++)

	{
		for(j=0;j<e2;j++)
		{
			sum=0;
			for(k=0;k<e1;k++)
			{
				sum=sum+ptr[i][k]*ptr1[k][j];
			}
			res[i][j]=sum;
		}

	}
	for(i=0;i<r1;i++)
	{
		for(j=0;j<e2;j++)
		{
			printf("%d\n",res[i][j]);
		}
	}
	printf("\n");
}




void main()
{
	void *vptr;
         vptr=multi;
	int ptr[R1][E1],ptr1[R2][E2],i,j;
	printf("matrix1\n");
	for(i=0;i<R1;i++)
	{
		for(j=0;j<E1;j++)
		{
			scanf("%d",&ptr[i][j]);
		}
	}
	printf("matrix2\n");
	for(i=0;i<R2;i++)
	{
		for(j=0;j<E2;j++)                                                                                                                                                           
		{

			scanf("%d",&ptr1[i][j]);
		}
	}
	if(R2==E1)
	{
		((void (*)(int,int,int,int,int(*)[],int(*)[]))vptr)(R1,R2,E1,E2,ptr,ptr1);
	//	multi(R1,R2,E1,E2,ptr,ptr1);
	}
	else
	{
		printf("invalid operation\n");
	}
}


