#include<stdio.h>
#include<string.h>
void main()
{
	int i,j;
	char arr[32],res[32];
	printf("enter the input string\n");
	scanf("%[^s",arr);
	for(i=0,j=0;arr[i]!='\0';i++)
	{
		if(((arr[i]>=65)&&(arr[i]<=90))||((arr[i]>=97)&&(arr[i]<=122)))
		{
			res[j]=arr[i];
	      		j++;
		}
		else
		
		
			continue;
		
	}
	printf("%s\n",res);
}


