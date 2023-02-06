#include<stdio.h>

void rotate_element(int *ptr,int n,int rot)
{
        int i,temp,count=0;
        /*      while(rot!=count)
                {

                temp=ptr[0];

                for(i=0;i<n-1;i++)
                {
                ptr[i]=ptr[i+1];


                }
                count++;
                ptr[i]=temp;
                }
                for(i=0;i<n;i++)
                {
                printf("%d\n",ptr[i]);
                }
                }

*/
        for(count=0;count!=rot;count++)
{
        temp=ptr[0];
        for(i=0;i<n-1;i++)
        {
                ptr[i]=ptr[i+1];
        }
        ptr[i]=temp;
}
for(i=0;i<n;i++)
{
        printf("%d\n",ptr[i]);
}
}


