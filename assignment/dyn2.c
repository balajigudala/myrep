#include<stdio.h>
void swap(int num1,int num2)
{
	num1=(num1^num2);
	num2=(num1^num2);
	num1=(num1^num2);
	printf("after swaping %d:%d\n",num1,num2);
}


