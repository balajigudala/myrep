#include<stdio.h>
int main()
{
	int num;
	int mask=0x3;
	printf("enter the input: ");
	scanf("%d",&num);
	if((num&mask)==0)
		printf("even\n");
	else
		printf("odd\n");
}
