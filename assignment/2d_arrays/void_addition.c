#include<stdio.h>

void sum(int r,int c,int (*ptr1)[c],int (*ptr)[c]);


void  main()
{

        int r1,c1,r2,c2;
	void *vptr;
	vptr=sum;


        printf("Enter number of Rows of matrix a: ");
        scanf("%d",&r1);
        printf("Enter number of Cols of matrix a: ");
        scanf("%d",&c1);
        int a[r1][c1];

 printf("\nEnter elements of matrix a: \n");
        read(r1,c1,a);
        //display(a,r1,c1);



        printf("Enter number of Rows of matrix b: ");
        scanf("%d",&r2);
        printf("Enter number of Cols of matrix b: ");
        scanf("%d",&c2);
        int b[r1][c2];

printf("\nEnter elements of matrix b: \n");
        red(r2,c2,b);

        //display(b,r2,c2);
        if((r1==r2)&&(c1==c2))
		((void (*)(int,int,int(*)[],int(*)[]))vptr)(r1,c1,a,b);
               // sum(r1,c1,a,b);

}


void read(int r1,int c1,int (*ptr)[c1])
{
        int i,j;
        for(i=0;i<r1;i++)
        {
                for(j=0;j<c1;j++)
                {
                        scanf("%d",&ptr[i][j]);

                }
        }
}
void red(int r2,int c2,int (*pt)[c2])
{
        int i,j;
        for(i=0;i<r2;i++)
        {
                for(j=0;j<c2;j++)
                {
                        scanf("%d",&pt[i][j]);

                }
        }
}


void sum(int r,int c,int (*ptr1)[c],int (*ptr)[c])
{

        int i,j;
        int re[r][c];




        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {

                        re[i][j]=(ptr1[i][j]+ptr[i][j]);
                }
        }
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {

                        printf("%d\n",re[i][j]);
                }
        }
}

