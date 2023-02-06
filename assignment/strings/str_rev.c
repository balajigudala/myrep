#include<stdio.h>
#include<string.h>
/*void main()
{
	char str[100];
	int i;
	printf("enter a string\n");
	scanf("%[^\n]s",str);                    //                 >>>>>>>>>>>> REVERSE ORDER OF THE STRING >>>>>>>>>>>>>
	int l=strlen(str);
	for(i=l;i>=0;i--)
	{
		printf("%c\n",str[i]);
	}
}*/






void str_rev(char* str,int l);
void main()
{
	char str[100];
	printf("enter a string\n");
	scanf("%[^\n]s",str);                      //             .............. REVERSE ORDER OF A STRING USING RECURSSION FUNCTION..............
	//printf("%s",str);
	int l=strlen(str);
	str_rev(str,l);
}

void str_rev(char* str,int l)
{
	if(l<0)
		return;
	printf("%c ",str[l]);

	str_rev(str,l-1);
}

