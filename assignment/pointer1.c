#include<stdio.h>
main()
{
	short int x=10;
	printf("%d\n",x);
	short int *ptr;
	ptr=&x;
        *ptr=20;
//	printf("%d:%d\n",x,ptr);
	printf("%p-%d-%ld-%ld\n",&x,x,sizeof(&x),sizeof(x));
	printf("%p-%ld\n",ptr,sizeof(ptr));
	printf("%d-%ld\n",*ptr,sizeof(ptr));
	printf("%p-%ld\n",&ptr,sizeof(&ptr));


}

