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
       // string_con(s1,s2);
        void (*ptr)(char*,char*);     function declaration
		ptr=string_con;     // assigning functions address to function pointer........
	(*ptr)(s1,s2);  // function calling.......
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
//                stat=mystrncmp(&src[i],dst,n)
                  int (*fptr)(char *,char *,int );// function declaration
		  fptr=mystrncmp;// assigning address to fun pointer
		  fptr(&src[i],dst,n); // function calling
                if(stat==0)
                {
                        c++;
                        i=i+n;
                }
                i++;
        }
       printf("%d\n",c);
/


#include<stdio.h>
#include<string.h>
void rept(char *ptr);



void main()
{
        char s1[100];
        printf("enter a statement\n");
        scanf("%[^\n]s",&s1);
       // rept(s1);
       void (*fptr)(char *);
       fptr=rept;
         fptr(s1);
}


void rept(char *ptr)
{
        int i,j,l,count=1;
        l=strlen(ptr);
        for(i=0;i<l;i++)
        {
                if(ptr[i]!=1)
                {
                        for(j=i+1;j<=l;j++)
                        {
                                if(ptr[i]==ptr[j])
                                {
                                        count++;
                                        ptr[j]=1;
                                }

                        }
                        printf("%c-%d\n",ptr[i],count);
                        count=1;
                }
        }
}
  



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
//        int ret=pal();
          int (*fptr)();
	  fptr=pal;
	int ret=fptr();

        if(ret==0)
                printf("palindrome\n");
        else
                printf("not a palindrome\n");
}*/


   
#include<stdio.h>
#include<string.h>

void int_ascii(int x)

{
        int i, sum,r,c=0;
        int temp=x;
        while(temp!=0)
        {
                c++;
                temp=temp/10;
        }
        char src[c];
        for(i=c-1;i>=0;i--)
        {
                r=x%10;
                x=x/10;
                sum=r+48;
                src[i]=sum;
        }
        src[c]='\0';

        printf("%s\n",src);
}



void main(void)
{
        int x;
        printf("enter a value\n");
        scanf("%d",&x);
//        int_ascii(x);
         
	void (*fptr)(int); // function declaration of function pointer
	fptr=int_ascii;// assigning address to function pointer
	fptr(x);// function calling

}

