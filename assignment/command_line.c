#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void binary(int *,int);
void ascending(int *,int);
void decending(int *,int);
void palindrome(int *,int);

main(int argc,char *argv[])
{
	int i;
	char c;
	if(argc<=2)
	{
		printf("less no. of inputs\n");
		exit(1);
	}
	else if (strlen(argv[1])==2)
	{
		if(argv[1][0]=='-')
		{
			if((argv[1][1]=='a')||(argv[1][1]=='b')||(argv[1][1]=='c')||(argv[1][1]=='d'))
				c=argv[1][1];
		}
		else
		{
			printf("invalid selection\n");
			//c='h';
		}
	}




	/*else
	  {
	  c='h';
	  }*/




	int l=argc-2,j=0,sum=0,temp,k=0,count=0;
	int *ptr;
	ptr=(int *)calloc(l,sizeof(int));
	for(i=2;i<l+2;i++)
	{
		sum=0;
		count=0;
		for(j=0;argv[i][j]!='\0';j++)
		{
			if(argv[i][j]=='-')
			{
				j++;
				if((argv[i][j]>='0')&&(argv[i][j]<='9')){
                                                             temp=argv[i][j]-48;
                                                       sum=sum*10+temp;
						       count++;
				}
				else {
					printf("Invalid input\n");
					exit(8);
				}

			}
			else if((argv[i][j]>='0')&&(argv[i][j]<='9')){
				temp=argv[i][j]-48;
			sum=sum*10+temp;
			}
			else{
				printf("Invalid input\n");
				exit(5);
			}
		}
		if(count==1)
			sum=-(sum);
	ptr[k]=sum;
	printf("%d\n",ptr[k]);
	k++;
	}



switch(c)
{
	case 'a':binary(ptr,l);
		 break;

	case 'b':ascending(ptr,l);
		 break;

	case 'c':decending(ptr,l);
		 break;

	case 'd':palindrome(ptr,l);
		 break;
}
}




/*>>>>>>>>>>>>>>>>>>>>>-------------- palindrome ----------- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


void palindrome(int *ptr, int l)
{
	int sum=0,temp,rem,i;
	for(i=0;i<l;i++)
	{
		temp=ptr[i];
		sum=0;
		while(temp!=0)
		{
			rem=temp%10;
			sum=sum*10+rem;
			temp=temp/10;
		}
		if(ptr[i]==sum)
		{
			printf("palindrome:%d\n",ptr[i]);
		}
		else 
			printf("not palindrome:%d\n",ptr[i]);
	}
}



/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   Desending order   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


void decending(int *ptr, int l)
{
	int temp,i,j;
	printf("decending order\n");
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(ptr[j]>ptr[i])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}

	for(i=0;i<l;i++)
	{
		printf("%d\n",ptr[i]);
	}
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     Asending order       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/





void ascending (int *ptr, int l)
{
	int temp,j,i;
	printf("ascending order\n");
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(ptr[j]<ptr[i])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
	for(i=0;i<l;i++)
	{
		printf("%d\n",ptr[i]);
	}
}



/*-------------------------------------   integer to binary   ------------------------------------------*/

void binary(int *ptr, int l)
{
	int i,j;
	for(i=0;i<l;i++)
	{
	//	printf("arr[%d]=%d",i,ptr[i]);
		for(j=31;j>=0;j--)
		{
			if((ptr[i]&(0x1<<j))==0)
				printf("0");
			else 
				printf("1");
		}
		printf("\n");
	}
}



















//printf("menu :\n -a binary\n -b ascending\n -c desending\n -d palindrome\n" );





