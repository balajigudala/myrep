#include<stdio.h>
int count_zeros(int);                   // FUNCTION DECLARATION
int onezeroone_repeat(int);
void binary_value(int);
int swap_bits(unsigned int,int,int);
int sum_digits(int);
void palindrome_integer(int);
int decimal_binary(int);
void  swap_variables(int,int);
//int uppercase_lowercase(int);//
//int character_integer(int);//
//int fibonacci_series(int);
void main(void)
{
	 unsigned int opt,res,num,x,y,t,rev=0,rem,sum=0,c,product=1,n,z,p,q,r;
        char up;
        char sub_opt;
        unsigned int i=0,count=0,b1,b2,temp;
	while(1)
		{
                printf("menu\n1.bitwise\n2.matematical operators\n3.swap\n enter ur option");
                scanf("%d",&opt);
                __fpurge(stdin);

		switch(opt){
			
			case 1:printf("select the option to perform bitwise operator\n a.no. of zeros\n b. no. of 101 repeatation\n c.printing binary value\n d.swaping of bits\nenter a char");
                               __fpurge(stdin);
                               scanf("%c",&sub_opt);
                             //  __fpurge(stdin);
                               //__fpurge(stdin);


                switch(sub_opt){

			case 'a':printf("enter the number in hexa:\n");                         // count no. of zeros.
			       scanf("%x",&num);                                     
			       res=count_zeros(num);  // FUNCTION CALL.
			       printf("%d\n",res);
			       break;

			case 'b':printf("enter the no. in hexa:\n");                            // 101 repeatations.
			       scanf("%x",&num);
			       res=onezeroone_repeat(num);
			       printf("%d\n",res);
			       break;

			case 'c':printf("enter the number in hexa:\n");                  // binary value
			       scanf("%x",&num);
			       binary_value(num);
			    //   printf("%d\n",res);
			       break;

			case 'd':printf("enter the number:\n");                         // swap th bits.
			       scanf("%x",&num);
				 printf("enter bits\n");
				 scanf("%d%d",&b1,&b2);
			       swap_bits(num,b1,b2);
			        break;
		}
		break;



			       case 2:printf("selsect the option for mathematical operator\n a.sum of digits\n b.palindrome\n c.decimal to binary\n");
                               scanf("%c",&sub_opt);
					printf("enter a value:\n");
					scanf("%d",&num);
				      switch(sub_opt){



					      case 'a':res=sum_digits(num);
						     printf("%d\n",res);    // sun of digits
						     break;

					      case 'b':palindrome_integer(num);      //palindrome
						     break;

					      case 'c':res=decimal_binary(num);      // decimal to binary
						     printf("%d\n",res);
						     break;
				      }
				      break;

                                case 3:printf("select the options to swap the content\n a.without third variable\n");
                                          scanf("%c",&sub_opt);
                                           switch(sub_opt)
                                             {
				        
				            case 'a':printf("enter x and y values\n");          // swaping bits without using third variable
					      scanf("%d %d",&x,&y);
			                      swap_variables(x,y);
					   
					      break;
			                      }
			                         break;  


			/*	case 'd':printf("select the options to perform ascii operations\na.upper case=lowercase\nb.character =integer\n");
				       scanf("%c",&sub_opt);
				       switch(sub_opt)
				       {
					       case 1:printf("enter a character:\n");
						      scanf("%c",&up);
						      res=uppercase_lowercase(up);
						      printf("%c\n",res);
						      break;
					       case 2:printf("enter a character:\n");
						      scanf("%d",&up);
						      res=character_integer(up);
						      printf("%c\n",res);
						      break;
				       }
				       break;
				        

				case'e':printf("enter 3 inputs");
					scanf("%d %d %d",&p,&q,&r);
					printf("%d %d",p,q);
					fibonacci_series(p,q,r);
					printf("%d\n",p,q,r);
					break;*/
		}
		}
}

         // FUNCTION DEFINATIONS.

int count_zeros(int num)
{
int count=0,i;
for(i=0;i<32;i++)                   //no. of zeros.
{
	if((num & (0x1<<i))==0) 
		count++;
} 
return count;
}




int onezeroone_repeat(int num)           // 101 repeatations
{
int count=0,i;
for(i=0;i<=32-3;i++)
{
	if((num &(0x7<<i))==(0x5<<(i)))
		count++;
}
return count;
}


void binary_value(int num)                     // binary value
{
	int count=0,i;
	for(i=31;i>=0;i--)
{
	if((num &(0x1<<i))==0) 
		printf("0");
	else
		printf("1");
}

}



int swap_bits(unsigned int num,int b1,int b2)                                        //   swap the bits
{
         int temp;	
	(b1>b2)?(temp=b1,b1=b2,b2=temp):0;
	num=((num &~((0x1<<b2)|(0x1<<b1)))|(num &(0x1<<b1))<<(b2-b1)|((num &(0x1<<b2))>>(b2-b1)));
        printf("%x\n",num);
}


int sum_digits(int sum)
{
	int x=sum,y,c=0;
while(x!=0)
{
	y=x%10;                          // sum of digits
	x=x/10;
	c=c+y;
}
return c;
}




void palindrome_integer(int rev)
{

	int x=0,y,t;
	t=rev;
while(t!=0)                                               // palindrome
{
	y=t%10;
	t=t/10;
	x=x*10+y;
}
if(x==rev)
	printf("palindrome\n");
else
 printf("not a palindrome\n");
}


int decimal_binary(int sum)
{	                                                      // decimal----- binary
	int c=0,rem,product=1,n;

	
	n=sum;
while(n!=0)
{
	rem=n%2;
	n=n/2;
	c=c+(rem*product);
	product=product*10;
}
return c;
}


void swap_variables(int x,int y)                              // swap the variables without third variable.
{

	x=x+y;
	y=x-y;
	x=x-y;
  printf("%d %d",x,y);
}






	

