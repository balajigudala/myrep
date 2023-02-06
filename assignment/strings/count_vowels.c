
/*  sheshuuee   ->>euuee ->  eu -2  -->5  */

#include<stdio.h>
#include<string.h>
int count_vowels(char *ptr);

void main()
{
	int res;
	char str[100];
	printf("enter a string\n");
	scanf("%s",str);
	res=count_vowels(str);
	printf("%d\n",res);
}


int count_vowels(char *ptr)
{
	int i,count=0,j;
	for(i=0;ptr[i]!=0;i++)
	{
		if((ptr[i]=='a')||(ptr[i]=='e')||(ptr[i]=='i')||(ptr[i]=='o')||(ptr[i]=='u')||(ptr[i]=='A')||(ptr[i]=='E')||(ptr[i]=='I')||(ptr[i]=='O')||(ptr[i]=='U'))

		{
			for(j=i+1;ptr[j]!='\0';j++)
			{
				if(ptr[i]==ptr[j])

				{
					ptr[j]=' ';
				}
			}


			count++;
		}
	}
	return(count);
}



