#include<stdio.h>
void main(int arg,char *str[])
{
	int i;
	for(i=0;i<arg;i++)
	{
		printf("%s-------%p\n",str[i],&str[i]);
	//	printf("%s-------%p\n",*str,&*str);
	}
}
