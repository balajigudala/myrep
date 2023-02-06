#include<stdio.h>
void main()
{
	unsigned int opt,num,x,y,t,rev,rem,sum=0,c,product=1,n,z,p,q,r;
	char up;
	char sub_opt;
	unsigned int i=0,count=0,b1,b2,temp;
//	while(1)
	{
		printf("select the options\n0.exit\n1.bitwise\n2.matematical operators\n3.swap\n4.upper to lower\n5.febonaci series\n enter ur option");
		scanf("%d",&opt);
		__fpurge(stdin);

		switch(opt){
	//		case 0:
	//			exit(0);
			case 1:printf("select the option to perform bitwise operator\n a.no. of zeros\n b. no. of 101 repeatation\n c.printing binary value\n d.swaping of bits\nenter a char");
			       scanf("%c",&sub_opt);
			       __fpurge(stdin);
			       		 //      printf("enter the value in hexa:");
					//	       scanf("%x",&num);

			       switch (sub_opt){

				       case 'a':printf("enter a no. in hexa:");                  // the no. of zeros.
						scanf("%x",&num);
						for(i=0;i<32;i++){
							if((num & (0x1<<i))==0) count++;
						}
						printf("the no. of 0's%d\n",count);
						break;


				       case 'b':printf("enter the no. in hexa:");               // the no. of 101 repeatations.
						scanf("%x",&num);
						for(i=0;i<=32-3;i++){
							if((num &(0x7<<i))==(0x5<<(i)))
								count++;
						}
						printf("the no. of 101 repeatation:%d\n",count);
						break;

				       case 'c':printf("enter the number in hexa:");                  // printing binary value.
						scanf("%x",&num);
						for(i=31;i>=0;i--)
						{
							if((num &(0x1<<i))==0) printf("0");
							else
								printf("1");
						}
						break;


				       case 'd':printf("enter the no. in hexa:");                         // swaping of bits.
						scanf("%x",&num);
						printf("enter the bits to be swapped b1:b2");
						scanf("%d:%d",&b1,&b2);
						(b1>b2)?(temp=b1,b1=b2,b2=temp):0;
						num=((num &~((0x1<<b2)|(0x1<<b1)))|(num &(0x1<<b1))<<(b2-b1))|((num &(0x1<<b2))>>(b2-b1));
						printf("after swapping:%x\n",num);
						break;

				       default:printf("invalid input");
			       }
			       break;
			case 2:printf("selsect the option for mathematical operator\n a.sum of digits\n b.palindrome\n c.decimal to binary\n");
			       scanf("%c",&sub_opt);
			      // printf("enter a input\n");
			      // scanf("%d",&num);

			       switch(sub_opt)
			       {
			       case 'a':printf("enter the value");
			                scanf("%d",&x);
			                 while(x!=0)
			                {
				       y=x%10;
				       x=x/10;
				       sum=sum+y;
			               }
			       printf("%d\n",sum);
			       break;
			case 'b':printf("enter a  value\n");
			       scanf("%d",&x);
			       t=x;
			       while(t!=0)
			       {
				       y=t%10;
				       t=t/10;
				       rev=rev*10+y;
			       }
			       printf("%d\n",rev);
			       if(rev==x)
				       printf("x is palindrome\n");
			       else
				       printf("x is not a palindrom\n");
			       break;
			case 'c':printf("enter x value");
			       scanf("%d",&x);
			       n=x;
			       while(n!=0)
			       {
				       rem=n%2;
				       n=n/2;
				       sum=sum+(rem*product);
				       product=product*10;
			       }
			       printf("%d\n",sum);
			       break;
			default:printf("invalid");
			       }
			       break;


			case 3:printf("select the options to swap the content\n a.without third variable\n b.using third variablr\n c.using bitwise operator\n");
			       scanf("%c",&sub_opt);
			    //   printf("enter the input\n");
			      // scanf("%d",&x);
			       switch(sub_opt)
			       {
				       case'a':printf("enter x and y values\n");
					       scanf("%d %d",&x,&y);
					       x=x+y;
					       y=x-y;
					       x=x-y;
					       printf("%d\n %d\n",x,y);
					       break;
				       case'b':printf("enter x and y values\n"); 
					       scanf("%d %d",&x,&y);
					       temp=x;
					       x=y;
					       y=temp;
					       printf("%d\n %d\n",x,y);
					       break;
				       case'c':printf("enter x and y values\n");
					       scanf("%d %d",&x,&y);
					       x=x^y;
					       y=x^y;
					       x=x^y;
					       printf("%d\n %d\n",x,y);
					       break;
			       }
			       break;
			case 4:printf("select the options to perform ascii operations\na.upper case=lowercase\nb.character =integer\n");
			       scanf("%c",&sub_opt);
			 //      printf("enter the inputs\n");
			   //    scanf("%c",&x);
			       switch(sub_opt)
			       {
				       case'a':printf("enter up char.\n");
					       __fpurge(stdin);
					       scanf("%c",&up);
					       if((up>=65)&&(up<=90))
					       {
						       up=up+32;
						       printf("%c\n",up);
					       }
					       else
						       printf("invalid input");
					       break;
				       case'b':printf("enter up char.\n");
					       __fpurge(stdin);
					       scanf("%c",&up);
					       if((up>=48)&&(up<=57))
					       {
						       up=up-48;
						       printf("%d\n",up);
					       }
					       else
						       printf("invalid input");
					       break;
			       }
			       break;
			case 5:printf("enter the 3 input\n");
			       scanf("%d %d %d",&p,&q,&r);
			       printf("%d %d",p,q);
			             while(count<r)
				     {

				       c=p+q;
				       p=q;
				       q=c;
				       count++;
				       printf("%d\n",c);
				     }
			       
			       break;
		}
	}
}



