#include<stdio.h>
main()
{
	int arr[128]={0};
	int i,max=0,j;
	char maxChar;
	char str[100];
	printf("enter the string\n");
	scanf("%[^\n]s",str);
	for(i=0;str[i]!='\0';i++)
	  arr[str[i]]++;
	for(i=0;i < 128;i++)
	{
		if(arr[i]>max)
		{
			if(i == ' ')
				continue;
			max=arr[i];
			maxChar = i;
		}
	}
	printf("max occurence: %d\n",max);
	printf("max char: %c\n",maxChar);
}
