#include<stdio.h>
main()
{
//	int*ptr=100;
//	printf("%d\n",*ptr);
	unsigned int x=0x11223344;
	unsigned char *ptr=&x;
	printf("%x:%d:%c\n",*ptr,*ptr,*ptr);
}

