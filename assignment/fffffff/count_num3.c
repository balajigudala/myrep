
#include<stdio.h>
int count_num(int)

{
	int count=0,x;

		if(x!=0){
			while(x!=0)
			{
				x=x/10;
				count++;
			}
			printf("%d",count);
		}
		else
			count++;
	printf("%d\n", count);
}

