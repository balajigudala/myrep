#include<stdio.h>
#include"myheader.h"

int main(int)
{
        int opt,num,res,x;
printf("select the option\n 1.reverse\n 2.sum of digits\n 3.count\n,enter ur option\n ");
                        scanf("%d",&opt);

                        switch(opt)
                        {
                                case 1:printf("enter the value\n");            // reverse the number
                               scanf("%d",&num);
				       res=reverse_num(num);
				       printf("%d\n",res);
                                      break;


                        case 2:printf("enter the value\n");                   //      sum of the digits
                               scanf("%d",&x);
			       res=sum_num(x);
                                break;


                        case 3:printf("enter the value\n");                   // count the digits
                               scanf("%d",&x);
			       res=count_num(x);
			       break;
			}
}

           

