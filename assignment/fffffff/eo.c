#include<stdio.h>
int main()
{
	int x,i;
	printf("Enter value");
	scanf("%x",&x);
	printf("enter number of bits");
	scanf("%d",&i);
	(((x<<i)&(0x1<<i))==(0x1<<i))?printf("odd"):printf("even");
	return 0;
}

