#include<stdio.h>
main()
{
	unsigned int x=0xffffffff;
unsigned char y;
y=x;
printf("%d\n",y);
y=x>>8;
	printf("%d\n",y);
y=x>>16;
	printf("%d\n",y);
	y=x>>24;
	printf("%d\n",y);
	
	

}


