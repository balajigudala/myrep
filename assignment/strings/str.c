#include<string.h>
#include<stdio.h>

int big=0,temp,ind,j;
char *str(char *a,int i)
{
	for(i;a[i]!='\0';i++)
	{
		for(j=i+1;a[j]!='\0';j++)
		{
			if(a[i]==a[j])
			{
				temp=j-i;
				if(temp>big)
				{
					big=temp;
					ind=i;
				}

				str(a,j);
			}
		}
	}
//	printf("len:%d -index:%d\n",big,ind);
}


void main()
{
	char a[100];
	int i=0,j,k=0,x;
	printf("string\n");
	scanf("%[^\n]s",a);
	x=strlen(a);
	printf("strlen =%d\n",x);
	str(a,i);
//	printf("new ------len:%d -index:%d",big,ind);
         int t=ind+big;
         for(j=ind+1;j<t;j++){
		 printf("j=%d t=%d\n",j,t);
		 printf("%c ",a[j]);
	 }
}
