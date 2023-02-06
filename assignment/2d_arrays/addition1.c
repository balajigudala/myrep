#include<stdio.h>
#define R 3
#define C 3
void main()
{
	int i,j,m1[R][C],m2[R][C],m3[R][C];
	printf("enter the matrix m1(%dx%d):\n",R,C);
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}

	printf("enter the matrix m2(%dx%d):\n",R,C);
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}

	// addition.........
	


	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			m3[i][j]=m1[i][j]+m2[i][j];
		}
	}
        
	printf("the output matrix m3 is\n");

	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%5d",m3[i][j]);
			
		}
			printf("\n");
	}
}


	
