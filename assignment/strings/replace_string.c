#include<stdio.h>
#include<string.h>
void main()
{
	char a[50];
	printf("enter a string\n");
	scanf("%[^\n]s",a);
	int i,j,k=0,c=0,r=0;
	char b[20];
	printf("string to be searched\n");
	scanf("%s",b);
	char res[20];
	printf("string to be replaced\n");
	scanf("%s",res);
	int len=strlen(b);
	int le=strlen(a);
	int l=strlen(res);
	int d=strlen(res)-strlen(b);
	for(i=0;a[i]!='\0';i++)
	{
		k=0;
		c=0;
		for(k=i,j=0;j<len;j++,k++)
		{
			if(a[k]==b[j])
				c++;
		}
		if(c==len)
		{
			
			for(j=le;j>=k;j--)
			{
				a[j+d]=a[j];
			}
		
		}

		if(c==len)
		{
		for(k=i,j=0;j<l;j++,k++)
                {
                        a[k]=res[j];
                }
		}

	}
	printf("%s",a);
}




