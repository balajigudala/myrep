//  printing integer to asciiii 

/*#include<stdio.h>
#include<string.h>

void int_ascii(int x)

{
	int i, sum,r,c=0;
	int temp=x;
	while(temp!=0)
	{
		c++;
		temp=temp/10;
	}
	char src[c];
	for(i=c-1;i>=0;i--)
	{
		r=x%10;
		x=x/10;
		sum=r+48;
		src[i]=sum;
	}
	src[c]='\0';
	
	printf("%s\n",src);
}



void main(void)
{
	int x;
	printf("enter a value\n");
	scanf("%d",&x);
	int_ascii(x);
}*/



// using void pointer 

#include<stdio.h>
#include<string.h>

void int_ascii(int x)

{
        int i, sum,r,c=0;
        int temp=x;
        while(temp!=0)
        {
                c++;
                temp=temp/10;
        }
        char src[c];
        for(i=c-1;i>=0;i--)
        {
                r=x%10;
                x=x/10;
                sum=r+48;
                src[i]=sum;
        }
        src[c]='\0';

        printf("%s\n",src);
}



void main(void)
{
        int x;
        printf("enter a value\n");
        scanf("%d",&x);
       // int_ascii(x);
       void *ptr;          /*........ declaring a void pointer........*/
       ptr=int_ascii;      /*......... assigning the address.....*/
      (( void (*)(int))ptr)(x);    /*.......function calll.......*/
}

