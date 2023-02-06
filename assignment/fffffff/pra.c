/*#include<stdio.h>
main()
{
		int arr[5],i;
		for(i=0;i<5;i++)
		{
		printf(" enter the value for");
		scanf("%d",&arr[i]);
		}
		printf("%d\n",arr[i]);

		}
		printf("the array elements are:\n");
		for(i=0;i<5;i++)
		printf("%d\n",arr[i]);
		printf("\n");
		return 0;
		}*/

//int large,small;
/*int i,temp,j,arr[5]={1,2,3,4,5};
//small=large=arr[0];
for(i=0,j=4;i<j;i++,j--)
{
//if(arr[i]<small)
//	small=arr[i];
//(arr[i]>large)
//	large=arr[i];
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
//printf("reverse of string:");
for(i=0;i<5;i++)
printf("%d\n",arr[i]);
printf("\n");
//printf("larger is%d\n smaller is%d\n",large,small);
}





int i,j,num,arr[15];
printf("enter a decimal value\n");
scanf("%d",&num);
i=0;
while(num>0)
{
arr[i]=num%2;
num=num/2;
i++;
}
printf("binary number is:");
for(j=i-1;j>=0;j--)
printf("%d\n",arr[j]);

}


int sum=0,x;

while(x!=0)
{
printf("enter the value\n");
scanf("%d",&x);
sum=sum+x;
x=x/10;

}
printf("%d\n",sum);
}

int arr[5],i;
for(i=0;i<5;i++)
{
	printf("enter the value for arr[%d]:",i);
	scanf("%d",arr[i]);
}
printf("the array elements are:\n");
for(i=0;i<5;i++)
{
	printf("%d\t",arr[i]);
}
}


int i;
int arr[5]={10,20,30,40,50};
for(i=0;i<5;i++)
{
	printf("value of arr[%d]=%d\t",i,arr[i]);
	printf("address of arr[%d]=%p\n",i,arr[i]);
}
return 0;
}

int *p;
int (*ptr)[5];
int arr[5];
p=arr;
ptr=&arr;
printf("p=%p,ptr=%p\n",p,ptr);
p++;
ptr++;
printf("p=%p,ptr=%p\n",p,ptr);


*/



#include<stdio.h>
//void read(int(*ptr)[3],int r,int e);
//void display(int **ptr,int r,int e);



/*void read(int(*ptr)[3],int r,int e)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<e;j++)
		{
			scanf("%d",&ptr[i][j]);
		}
	}
}




void display(int ptr[3][3],int r,int e)
{
	int i,j;
	 for(i=0;i<r;i++)
        {
                for(j=0;j<e;j++)
                {
			printf("%p---------------%d\n",&ptr[i][j],ptr[i][j]);
		}
	}
}



void main()
{
	int r ,e;
	printf("enter the no. of rows\n");
	scanf("%d",&r);
	__fpurge(stdin);
	printf("enter the no. of elements\n");
	scanf("%d",&e);
	int arr[r][e];
	read(arr,r,e);
	display(arr,r,e);
}*/

/*#include<stdio.h>
main()
{
	int arr[5],i,even=0,odd=0;
	for(i=0;i<5;i++)
	{
		printf("the elements arr[%d]:",i);
		scanf("%d",&arr[i]);

		if(arr[i]%2==0)
			even++;
		else 
			odd++;
	}
	printf("even numbers=%d,odd numbers=%d\n",even,odd);
}
*/



/*#include<stdio.h>
main()
{
	int i,max,min,arr[5]={1,2,3,4,5};
	min=max=arr[0];
	for(i=0;i<5;i++)
	{
		if(arr[i]<min)
			min=arr[i];
			if(arr[i]>max)
				max=arr[i];
	}
	printf("max=%d,min=%d\n",max,min);
}

#include<stdio.h>
 void main()
{
	int arr[5]={1,2,0,4,9};
	int item,i;
	printf("enter the element to be searched:");
	scanf("%d",&item);
	for(i=0;i<5;i++)
	{
		if(item==arr[i])
		{
			printf("%d found at a position %d\n",item,i+1);
			break;
		}
	}
	if(i==5)
		printf("item %d not found in array\n",item);
}
*/
/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *ptr,n,i;
	printf("enter the no. of integers to be entered\n");
	scanf("%d",&n);
	ptr=(int *)calloc(n,sizeof(int));
	if(ptr==NULL)
	{
		printf("failed to allocate memeory\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	
		printf("enter a integer\n");
		scanf("%d",(ptr+i));
	}

	for(i=0;i<n;i++)

		printf("%d\t",ptr[i]);
}
	*(ptr+i)=i*2;
	ptr=(int *)realloc(ptr,9*sizeof(int));
{
	if(ptr==NULL)
	{
		printf("failed to allocate memeory\n");
		exit(1);
	}
for(i=5;i<9;i++)
	*(ptr+i)=i*10;
for(i=0;i<9;i++)
	printf("%d ",ptr[i]);
return 0;
}
}


int i,j,rows;
int (*ptr)[4];
printf("enter the rows\n");
scanf("%d",&rows);
ptr=(int (*)[4])malloc(rows*4*sizeof(int));
for(i=0;i<rows;i++)
for(j=0;j<4;j++)
{
	printf("enter ptr[%d][%d]:",i,j);
	scanf("%d",&ptr[i][j]);
}
printf("the matrix is:\n");

for(i=0;i<rows;i++)
for(j=0;j<4;j++)
{
	printf("enter ptr[%d][%d]:",i,j);	
	printf("%5d",ptr[i][j]);
	printf("\n");
}
free(ptr);
}
*/
#include<stdio.h>
#include<string.h>
void main()

{
	/*
	char str[20];
	printf("enter a name:");
	gets(str);
	printf("entered name is:");
	puts(str);
}
*/


char str[20]="sheshu ";
char str2[20]="reddy ";
strcat(strcat(str,str2),"bose");
printf("str-%s\n",str);
}












































