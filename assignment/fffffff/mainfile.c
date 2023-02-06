#include<stdio.h>
#include<stdlib.h>
char* rem_space(char *str);
void rotate_element(int *ptr,int n,int );

void main()
{
        char  str[100];
        char* res;
        int n,m,k;
        int  opt;
        int ptr[100];
        int i;


        printf("menu\n 0.exit\n 1.remove space\n 2.rotate elements\n enter your options :");
        scanf("%d",&opt);
        __fpurge(stdin);
        while(1)
        {
                switch(opt)

                {

                        case 0:  exit(0);
                                 break;
/*
                        case 1:
                                 printf("enter a string\n");
                                 scanf("%[^\n]s",str);
                                 res= rem_space(str);
                                 printf("%s\n",res);
                                 break;
*/
                        case 2: printf("enter number of elements\n");
                                scanf("%d",&n);
                                printf("enter the elements\n");
                                for(i=0;i<n;i++)
                                {
                                        scanf("%d",&ptr[i]);
                                }

                                //      scanf("%d",&k);
                                printf("enter the number of elements to be rotated\n");
                                __fpurge(stdin);
                                scanf("%d",&m);
                                rotate_element(ptr,n,m);
                                break;
                }
                break;
        }
}
                                                                                                                                                                                   

/*char * rem_space(char *str)
{
        int i,j=0;
        for(i=0;str[i]!='\0';i++)
        {
                while(str[i]==' ')
                {
                        i++;
                        if(str[i]!=' ')
                        {
                                i--;
                                goto print;
                        }
                }
print:
                str[j]=str[i];
                j++;
        }
        str[j]='\0';
        return str;
}*/




