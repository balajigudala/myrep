#include<stdio.h>
main()
{
	int x=5;
	printf("%d\n", x++);
	x=5;
	printf("%d\n",++x);
	x=5;
	printf("%d-%d\n", x++, x++);
	printf("%d\n", x);
	x=5;
	printf("%d-%d\n",++x,++x);
	x=5;
	printf("%d-%d\n", ++x, x++);
	x=5;
	printf("%d-%d\n",x++,++x);
	x=5;
	printf("%d-%d-%d\n", x++,++x,x++);
	x=5;
	printf("%d-%d-%d-%d\n", ++x,++x,x++,++x);
}
