#include<stdio.h>
#define R 4 
#define C 4
void main()
{
	int arr[R][C];
	int i,j,m,n,k,l;
	printf("enter the matrix\n");
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	for(m=0,n=R-1;m<=n;m++,n--)
	{
		for(i=m;i<=n;i++)
			printf("%d\t",arr[m][i]);

		for(j=m+1;j<=n;j++)
                        printf("%d\t",arr[j][n]);
		
		for(k=n-1;k>=m;k--)
			printf("%d\t",arr[n][k]);

		for(l=n-1;l>=m+1;l--)
			printf("%d\t",arr[l][m]);
	}
	printf("\n");
}
