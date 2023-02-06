//counting letters in strings
#include<stdio.h>
#include<string.h>
void rept(char *ptr);



void main()
{
	char s1[100];
	printf("enter a statement\n");
	scanf("%[^\n]s",s1);
	rept(s1);
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




// using void pointer..........


/*void main()
{
        char s1[100];
        printf("enter a statement\n");
        scanf("%[^\n]s",&s1);
  //      rept(s1);
        void *vptr;      // declaring the void pointer.....
	vptr=rept;       // assigning the address to the pointer 
	((void (*)(char *))vptr)(s1);    // function call......
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
*/
