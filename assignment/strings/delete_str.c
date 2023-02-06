#include<stdio.h>
#include<string.h>
int del_str(char *ptr,char n);
int main()
{
	char str[100];
	char str1[100];
	char element;
	int res=0,l1,i,j=0;
	printf("enter the string\n");
	scanf("%[^\n]s",str);
	printf("enter the elements\n");
	__fpurge(stdin);
	scanf("%c",&element);
	l1=strlen(str);
	res=del_str(str,element);
	if(res<l1)
	{
		for(i=0;i<l1;i++)
		{
			if(str[i]==element);
			else
			{
				str1[j]=str[i];
				j++;
				continue;
			}
		}
		printf("%s",str1);
	}
	else
		printf("not found\n");
	printf("\n");
}



int del_str(char *ptr,char n)
{
	int i;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]==n)
		{
			return i;
		}
		else
			continue;
	}
	return i;
}

