#include<stdio.h>
#include<string.h>

char* strrev(char *,int,int);

void main()
{
	char src[100];
	printf("enter a string\n");
	scanf("%[^\n]s",src);
	int l=strlen(src);
	int i=0;
	char *res; 
	res=strrev(src,i,l-1);
	printf("%s\n",res);
}
 
char* strrev(char * src,int i,int l)
{
	char temp;
	temp=src[i];
	src[i]=src[l];
	src[l]=temp;
	i++;
	l--;
	if(i<l)
	{
		strrev(src,i,l);
	}
	return src;
}




