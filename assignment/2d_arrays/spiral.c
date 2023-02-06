#include<stdio.h>
int main()
{
	int i,j;
	int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
for(i=0,j=0; j<4;j++)
{
printf("%d\t", arr[i][j]);
}
for(i=1,j=3;i<4; i++)
{
	printf("%d\t", arr[i][j]);
}
for(i=3, j=2; j>=0; j--)
{
	printf("%d\t", arr[i][j]);
}
for(i=2, j=0; i<=1; i--)
{
	printf("%d\t", arr[i][j]);
}

for(i=2, j=0; i>0; i--)
{
	printf("%d\t", arr[i][j]);
	}
for(i=1,j=1; j<=2; j++)
{
	printf("%d\t", arr[i][j]);
}

for(i=2, j=2; j>=1; j--)
{
	printf("%d\t", arr[i][j]);
}

	
printf("\n");
}
