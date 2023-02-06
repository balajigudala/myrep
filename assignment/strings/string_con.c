// string concatination................

/*#include<stdio.h>
#include<string.h>
void string_con(char *ptr1,char *ptr2);
void main()
{
	char s1[100],s2[100];
	printf("enter a string\n");
	scanf("%[^\n]s",s1);
	__fpurge(stdin);
	printf("enter second string\n");
	scanf("%[^\n]s",s2);
	string_con(s1,s2);
}



void string_con(char *ptr1,char *ptr2)
{
	int l1,l2,i;
	l1=strlen(ptr1);
	l2=strlen(ptr2);
	int l3=l1+l2;
	char s3[l3+1];
	for(i=0;i<l1;i++)
	{
		s3[i]=ptr1[i];
}
int j=0;
for(i;i<l3;i++)
{
	s3[i]=ptr2[j];
	j++;
}
s3[l3]='\0';
printf("%s\n",s3);
}*/



// using void pointer........

#include<stdio.h>
#include<string.h>
void string_con(char *ptr1,char *ptr2);
void main()
{
        char s1[100],s2[100];
        printf("enter a string\n");
        scanf("%[^\n]s",s1);
        __fpurge(stdin);
        printf("enter second string\n");
        scanf("%[^\n]s",s2);
     //   string_con(s1,s2);
      void *ptr;     // declaring the void pointer.....
      ptr=string_con; // assigning the address to the pointer....
     ( (void (*)(char *, char *))ptr)(s1,s2);     // function declaration.......
}



void string_con(char *ptr1,char *ptr2)
{
        int l1,l2,i;
        l1=strlen(ptr1);
        l2=strlen(ptr2);
        int l3=l1+l2;
        char s3[l3+1];
        for(i=0;i<l1;i++)
        {
                s3[i]=ptr1[i];
}
int j=0;
for(i;i<l3;i++)
{
        s3[i]=ptr2[j];
        j++;
}
s3[l3]='\0';
printf("%s\n",s3);
}


