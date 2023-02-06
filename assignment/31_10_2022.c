#include<stdio.h>
main()
{
	int i;
	signed int z=0x0000000;
	signed int x=0x11223344;
	signed int y=0xaabbccdd;
	signed char *ptr1=&x;
	signed char *ptr2=&y;
	signed char *ptr3=&z;
	for(i=0;i<4;i++)
	{
		if(i%2==0)
			ptr3[i]=ptr1[i];
		else
			ptr3[i]=ptr2[i];
	}
	printf("0x%x\n",z);
}
