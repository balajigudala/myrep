#include<stdio.h>
#include<string.h>
void main()
{
	char arr[5][10]={"lord","happy","sheshu","bhargavi","redddy"};
	char temp[10];
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("string=%s\t",arr[i]);
		printf("address of string=%p\n",arr[i]);
		printf("\n");
	}
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(strcmp(arr[i],arr[j])>0)
			{
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}
		}

	}
	printf("after sorting\n");
	for(i=0;i<5;i++)
		printf("%s\n",arr[i]);

}

