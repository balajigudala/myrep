#include<stdio.h>
#include<stdlib.h>
int add_num(int,int);
int sub_num(int,int);
int mul_num(int,int);
float div_num(float,float);
void main(void)
{
	int x,y,opt,z;
	float a,b,c;
	char sub_opt;
	while(1)
	{
		printf("menu\n 0.exit\n 1.calculator\n enter your option\n");
		scanf("%d",&opt);
		__fpurge(stdin);


		switch(opt)
		{
			case 0:  exit(0);
			case 1:printf("select the option to perform calculator \n a.addition\n b. subtraction\n c.multiplication\n d.division\n enter a char");
			       __fpurge(stdin);
			       scanf("%c",&sub_opt);

			       //   printf("enter the inputs\n");
			       //  scanf("%d %d",&x,&y);

			       //  printf("enter the inputs\n");
			       // scanf("%f %f",&a,&b);


			       switch(sub_opt)
			       {

				                                                        
				       case'a':  printf("enter the inputs\n");       // addition
						 scanf("%d %d",&x,&y);
						 add_num(x,y);
						 break;

				       case'b':  printf("enter the inputs\n");
						 scanf("%d %d",&x,&y);
						 sub_num(x,y);                 // subtraction
						 break;

				       case'c':  printf("enter the inputs\n");
						 scanf("%d %d",&x,&y);
						 mul_num(x,y);                 // multipilcation
						 break;

				       case'd': printf("enter the inputs\n");
						scanf("%f %f",&a,&b);
						div_num(a,b);                  // division
						break;
			       }
		}
	}

}






int add_num(int x,int y)
{
	int z;
	z=x+y;
	printf("%d\n",z);
}


int sub_num(int x,int y)
{
	int z;
	z=x-y;
	printf("%d\n",z);
}

int mul_num(int x,int y)
{
	int z=0,count=0;
	while(count<y)
	{
		z=z+x;
		count++;
	}
	printf("%d\n",z);
}



float div_num(float a,float b)
{
	float c;
	c=a/b;
	printf("%f\n",c);
}







