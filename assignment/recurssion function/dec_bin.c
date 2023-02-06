#include<stdio.h>

/*void dec_bin(int num,int i);

	void main()
{
	int num;
	printf("enterr a number\n");
	scanf("%d",&num);
	int i=31;
	dec_bin(num,i);
}


void dec_bin(int num,int i)
{
	if(i>=0)
	{
		(num&(0x1<<i))?printf("1"):printf("0");
		i--;
		dec_bin(num,i);
	}
}

*/

long int dec_bin(long int num,long int,long int);

void main()
{
	long int i=1;
	long int rs,num;
	printf("enter a number\n");
	scanf("%ld",&num);
	rs=dec_bin(num,0,i);
	printf("%ld\n",rs);
}


long int dec_bin(long int temp,long int sum,long int i)

{
	long int rem,p;
	if(temp>0)
	{
		rem=temp%2;
		sum=sum+rem*i;
		i=i*10;
		temp=temp/2;
		sum=dec_bin(temp,sum,i);
	}	
	//	printf("%d\n",sum);
	
	return sum;
}


