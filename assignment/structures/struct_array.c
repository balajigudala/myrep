#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct employee
{
	char name[32];
	int id;
	float salary;
	char gen;
};

void read(struct employee *,int);
void display(struct employee*,int);


void main()
{
	/*	struct employee e[3];
		printf("%p-%ld\n",e,sizeof(e)); 				//<<<<<<<<<<<<<<<<<<<< statically allocated memory >>>>>>>>>>>>>>>>
		read(e,3);
		display(e,3);
		}*/





struct employee *ptr=(struct employee*)malloc(3*sizeof(struct employee));
if(ptr==NULL)
{
	printf("failed to allocate memory\n");                                 // <<<<<<<<<<< dynamically allocated memory >>>>>>>>
	exit(1);
}
printf("%p------%ld\n",ptr,sizeof(ptr));
read(ptr,3);
display(ptr,3);
}






void read(struct employee*ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter employee name:\n");
		scanf("%s",ptr[i].name);
		__fpurge(stdin);
		printf("enter employee id:\n");
		scanf("%d",&ptr[i].id);
		__fpurge(stdin);
		printf("enter employee salary:\n");
		scanf("%f",&ptr[i].salary);
		__fpurge(stdin);
		printf("enter employee gender:\n");
		scanf("%c",&ptr[i].gen);
		__fpurge(stdin);
	}
}



void display(struct employee *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%p-%ld\n",&ptr[i],sizeof(ptr[i]));
		printf("%-15p-%-15s-%ld\n",ptr[i].name,ptr[i].name,sizeof(ptr[i].name));
		printf("%-15p-%-15d-%ld\n",&ptr[i].id,ptr[i].id,sizeof(ptr[i].id));
		printf("%-15p-%-15f-%ld\n",&ptr[i].salary,ptr[i].salary,sizeof(ptr[i].salary));
		printf("%-15p-%-15c-%-ld\n",&ptr[i].gen,ptr[i].gen,sizeof(ptr[i].gen));
	}
}				

