#include<stdio.h>
#include<string.h>

int mystrncmp(char *src,char *dst,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(src[i]!=dst[i])
		return 1;
	}
	return 0;
}



void main()
{
	int stat=0;
	int c=0;
	int i;
	int n,m;
//	char src[100]="hi hello hi hi";
//	char dst[10]="hi";
	char src[100];
	char dst[100];
	printf("enter a string\n");
	scanf("%[^n\n]s",src);
	__fpurge(stdin);
	printf("enter a string\n");
	scanf("%s",dst);
	n=strlen(dst);
	m=strlen(src);
	for(i=0;i<=(m-n);)
	{
		stat=mystrncmp(&src[i],dst,n);
		if(stat==0)
		{
			c++;
			i=i+n;
		}
		i++;
	}
	printf("%d\n",c);
}


// using void pointer 



/*#include<stdio.h>
#include<string.h>

int mystrncmp(char *src,char *dst,int n)
{
        int i;
        for(i=0;i<n;i++)
        {
                if(src[i]!=dst[i])
                return 1;
        }
        return 0;
}



void main()
{
        int stat=0;
        int c=0;
        int i;
        int n,m;
//      char src[100]="hi hello hi hi";
//      char dst[10]="hi";
        char src[100];
        char dst[100];
        printf("enter a string\n");
        scanf("%[^n\n]s",src);
        __fpurge(stdin);
        printf("enter a string\n");
        scanf("%s",dst);
        n=strlen(dst);
        m=strlen(src);
        for(i=0;i<=(m-n);)
        {
              //  stat=mystrncmp(&src[i],dst,n);
               void *ptr;       // declaration of void pointer......
	       ptr=mystrncmp;   // assigning its address to the pointer......
	      (( void (*)(char *,char *,int))ptr)(&src[i],dst,n);    // function calll..........
	       	if(stat==0)
                {
                        c++;
                        i=i+n;
                }
                i++;
        }
        printf("%d\n",c);
	
}*/








