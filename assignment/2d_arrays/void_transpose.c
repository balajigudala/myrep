#include<stdio.h>
#define R 3
#define C 3

void read(int r,int c,int (*ptr)[c]);
void transpose(int r,int c,int(*ptr)[c]);

void main()
{
	void *vptr;
	vptr=transpose;
        int r,c;
        int ptr[R][C];
         read(R,C,ptr);
         if(R==C)
		 ((void(*)(int,int,int(*)[]))vptr)(R,C,ptr);
        // transpose(R,C,ptr);
         else
                 printf("invalid input\n");
}

void read(int r,int c,int(*ptr)[c])
{
        int i,j;
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        scanf("%d",&ptr[i][j]);
                }

        }
}





void transpose(int r,int c,int(*ptr)[c])
{
        int i,j;
         int res[C][R];
        for(i=0;i<R;i++)
        {
                for(j=0;j<C;j++)
                {
                   res[j][i]=ptr[i][j];
                }
        }

for(i=0;i<R;i++)
{
        for(j=0;j<C;j++)
        {
        printf("%d ",res[i][j]);
  }
        printf("\n");
}
}

