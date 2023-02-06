#include<stdio.h>
#include<string.h>
void main()
{
	char str[50];
	printf("enter a string\n");
	scanf("%[^\n]s",str);
	int i,j,k;
	for(i=0;str[i]!='\0';i++)
	{
		for(j=i;str[j]!='\0';j++)
		{
			if(str[j]==' ')
			{
				for(j;str[j]!='\0';j++)
				{
				str[j]=str[j+1];

				}
			}
		       	if(str[i]==' ')
                        {
                                for(k=i;str[k]!='\0';k++)
                                {
                                str[k]=str[k+1];

                                }
                        }

		}
	}
	printf("%s",str);
}
