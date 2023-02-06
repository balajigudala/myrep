#include<stdio.h>
#include<string.h>

int palindrome(char *);

void main(int arg,char *str[])
{
	int i,stat;
	for(i=1;i<arg;i++)
	{
		stat=palindrome(str[i]);
		if(stat==0)
		{
			printf("%-30s--------palindrome\n",str[i]);
		}
		else
			printf("%-30s......not a palindrome\n",str[i]);
	}
}
int palindrome(char *cptr)
{
	int i,j,k;
	k=strlen(cptr);
	for(i=0,j=k-1;i<j;i++,j--)
	{
		if(cptr[i]!=cptr[j])
			return -1;
	}
	return 0;
}

