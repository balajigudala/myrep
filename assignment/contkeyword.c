// program on constant keywords.....

#include<stdio.h>
main()
{

/*	const char x=10;    // understanding constant keyword........
	printf("%d\n",x);

	const char x=10;
	printf("%d\n",x);
	x=20;
	printf("%d\n",x)     // compilation error because data cant be modified...here the dtat of x is constant

	const char x=10;
	char *ptr=&x;
	printf("%d\n",x);
         *ptr=11;
	 printf("%d\n",x);  // we can modify the data in the address location by using pointers .......
*/



/* ..............constant data.....................*/
	
	
/*	int y=20;
	int x=10;
	const int *ptr;
	ptr=&x;                   // here the data will be constant i.e,the data cannot be modified means the data stored in varibale will be constant the value cannot be changed...
	printf("%d\n",*ptr);      //   ....we cannot modify x value by *ptr but we can change the address in ptr.........
        ptr=&y;
	printf("%d\n",*ptr);

*/


	/*.....................constant addresssss...................*/


/*	int x=10;
	int * const ptr=&x;
	*ptr=20;
	int y=30;
	printf("%p\n",ptr);     // >>>>>>>>> here the address of the variable is constant <<<<<<<<<<<<
	printf("%d\n",x);
*/


	/*..................constant address and constant data.................*/


/*	int x=10;
	int y=20;
	const int* const ptr=&x;
	printf("%d-%p\n",x,ptr);      //...... here the variabls address and the data stored in that adddress will be constant that means they cannpt be modified.........
*/


	int x[5]={10,20,30,40,50};
	display(x,5);
}
void display(int x[5],int n)
{
	int i;
	printf("%d\n",sizeof(x));
	for(i=0;i<n;i++)
		printf("%d\n",x[i]);






}

