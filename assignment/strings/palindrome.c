// palindrome.....

#include<stdio.h>
#include<string.h>
int pal()
{
	char s[100];
	printf("enter a word\n");
	scanf("%s",&s);
	int l,i;
	char c[100];
	for(i=0;s[i]!='\0';i++)
		c[i]=s[i];
	c[i]='\0';
	char temp='\0';
	l=strlen(s);
	for(i=0;i<(l/2);i++)
	{
		temp=s[i];
		s[i]=s[l-i-1];
		s[l-i-1]=temp;
	}
	for(i=0;s[i]!=0;i++)
	{
		if(s[i]!=c[i])
			return -1;
	}
	return 0;
}




void main()
{
	int ret=pal();
	if(ret==0)
		printf("palindrome\n");
	else 
		printf("not a palindrome\n");
}












// using void pointer........

/*#include<stdio.h>
#include<string.h>
int pal()
{
        char s[100];
        printf("enter a word\n");
        scanf("%s",&s);
        int l,i;
        char c[100];
        for(i=0;s[i]!='\0';i++)
                c[i]=s[i];
        c[i]='\0';
        char temp='\0';
        l=strlen(s);
        for(i=0;i<(l/2);i++)
        {
                temp=s[i];
                s[i]=s[l-i-1];
                s[l-i-1]=temp;
        }
        for(i=0;s[i]!=0;i++)
        {
                if(s[i]!=c[i])
                        return -1;
        }
        return 0;
}




void main()
{
    //    int ret=pal();
     int ret;
     void *ptr;       // declaring the void pointer
     ptr=pal;         // assigning the address to the pointer
     ret=((int (*)())ptr)();     // function call.....
        if(ret==0)
                printf("palindrome\n");
        else
                printf("not a palindrome\n");
}

*/
