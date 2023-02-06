#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	char temp;
	printf("enter a string\n");
	scanf("%[^\n]s",str);
	int i,j;
	for(i=0;str[i]!='\0';i++)
	{
		temp=str[i];
		for(j=i+1;str[j]!='\0';j++)
		{
			if(temp==str[j])
			{
				str[i]=' ';
				str[j]=' ';
			}
		}
	}
	int k=0;
	for(i=0;str[i]!='\0';i++)
	{

		if(str[i]!=' ')
		{
			str[k]=str[i];
			k++;
		}
	}
	
	str[k]='\0';
	
	printf("%s\n",str);

}
