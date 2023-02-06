// program on pointers and its understanding
/*#include<stdio.h>
main()
{
	 int *ptr1=0x5000;
          int*ptr2=0x5008;
	printf("%d\n",(ptr2-ptr1));
	int x[5]={1,2,3,4,5};
	int *ptr=x;
	int ret;
//	ret=(&ptr[2]-&ptr[0]);
//	ret=((void *)&ptr[2]-(void *)&ptr[0]);
	ret=((char *)&ptr[2]-(char *)&ptr[0]);
	ret=((int *)&ptr[2]-(int *)&ptr[0]);
	printf("%d\n",ret);

	}*/

		// program for double pointer.............

#include<stdio.h>
main()
{
	int x=10,z;
	int *ptr=&x;
	int **dptr=&ptr;

	// for single pointer.......
/*	
	printf("%p\n",ptr);      //.....variables base address......
	printf("%p\n",&ptr);     //......single pointers base addresss.......
	printf("%d\n",*ptr);     //......variable data or value address or *(address)......
	



       // for doubler pointer........[double pointers size depends upon machine type......we mostly use 8bytes]

	printf("%p\n",dptr);      //.....single pointers  base address......
	printf("%p\n",&dptr);      //.....double pointers base address......
	printf("%p\n",*dptr);      //.....variables base address......
	printf("%d\n",**dptr);      //.....value(data) of that address......
*/

	printf("%p\n",*dptr);
           z=*dptr;
	printf("%p\n",z);
}

