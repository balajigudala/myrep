#include<stdio.h>
#include<string.h>
void main()
{
	char src[100],dst[100];
	printf("enter the string\n");
	scanf("%[^\n]s",src);
	int l1,i,j=0,k;
	l1=strlen(src);

	for(i=0;i<=l1;i++)
	{
		if((src[i]==' '||src[i]=='\0'))
		{
			k=i;
			dst[k]=' ';
			for(j;(j<i);j++)
			{
				k--;
				dst[j]=src[k];
			}
			j++;
		}

		dst[j]='\0';

	}
	printf("%s\n",dst);
	printf("\n");
}


