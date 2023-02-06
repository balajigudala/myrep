#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

//------------------------------------------------------Global Variables---------------------------------------------------------
int i=0;
int k=0;
//-----------------------------------------------------Function Declarations-----------------------------------------------------

struct employee * allocation(struct employee *,int n);
void deallocation(struct employee *,int n);
void read(struct employee *,int n);
void display(struct employee *,int n);
void swap(struct employee *ptr1,int n);
//-----------------------------------------------------Struct Datatypes----------------------------------------------------

struct dob
{
	int date;
	int month;
	int year;
};
struct employee
{
	char name[32];
	float salary;
	struct dob dt;
};



struct employee_ops
{
	struct employee *(*memory_allocation)(struct employee *,int);
	void (*f_read)(struct employee *,int);
	void (*f_swap)(struct employee *,int);
	void (*f_display)(struct employee *,int);
	void (*memory_deallocation)(struct employee *,int);
};




//----------------------------------------------------------main function---------------------------------------------------------


void main()
{
	struct employee *e1=NULL;
	int n;
	struct employee_ops op;
	
	
	
	//-------------------------------------------------function pointers--------------------------------------------------
	op.memory_allocation=allocation;
	op.f_read=read;
	op.f_swap=swap;
	op.f_display=display;
	op.memory_deallocation=deallocation;
	
	
	int opt;
	while(1)
	{
		printf("\nMENU:\n0.Exit\n1.Allocation\n2.Read\n3.Swap\n4.Display\n5.Deallocation\n");
		printf("Enter your option:");
		scanf("%d",&opt);
		
		
		switch(opt)
		{
			case 0:exit(0);
			
			case 1:printf("Enter no.of employees:");
			       scanf("%d",&n);
			       i++;
			       if(i==1)
			       {
				       e1=op.memory_allocation(e1,n);                                   //function call to allocate memory
				       if(e1==NULL)
					       printf("Failed to allocate memory\n");
				       else
					       printf("\n-------------------------------Memory is allocated-------------------------------------------\n");
			       }
			       break;
			
			
			case 2:
			       if(i==1)
			       {
				       op.f_read(e1,n);     				       //function call to read employee detailes
				       k++;
			       }
			       else if(i==0)
				       printf("\n-------------------------------------Kindly allocate memory before giving inputs------------------------------------------------\n");
			       break;
			
			
			case 3:if((i==0)||(k==0))
			       {
				       printf("\n--------------------------------memory is not allocated---------------------------------------\n");
			       }
			       else if(i==k)
			       {
				       op.f_swap(e1,n);                                           //function call to swap two employee details
			       }
			       break;
			
			
			case 4:if(k==0)
				       printf("\n--------------------------memory is destoryed so please allocate memory---------------------------------\n");
			       else
			       {
				       if(k>0)
				       {
					       op.f_display(e1,n);                                   //function call to display employee details
				       }
				       else if(i==0)
					       printf("\n--------------------------------------Memory is deallocated-----------------------------------------------\n");
				       /*   else if(k==0)
					    printf("..........memory is destoryed so please allocate memory..............\n");*/
			       }
			       break;
			
			
			case 5:if(i==0)
				       printf("\n----------------------------Memory is not allocated, Kindly allocate memory-----------------------------------\n");
			       else
			       {
				       op.memory_deallocation(e1,n);                        //function call to deallocate memory
				       i--;
				       k=0;
				       printf("\n-------------------------------Memory is deallocated--------------------------------------\n");
			       }
			       break;
			
			
			default:printf("Please enter valid option\n");
		}
	}
}

//-------------------------------------------------------------function definition for allocating memory-----------------------------------------------------------
struct employee *allocation(struct employee *e1,int n)
{
	struct employee *ptr=(struct employee *)malloc(n*sizeof(struct employee));
	return ptr;
}
//-------------------------------------------------------------function definition for deallocating memory----------------------------------------------------------- 
void deallocation(struct employee * ptr,int n)
{
	free(ptr);
}


//-------------------------------------------------------------function definition to read detailes of two employees----------------------------------------------------------------------


void read(struct employee *ptr,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		printf("---------------------------------------Enter detailes of employee %d------------------------------------------------------\n",j+1);
		printf("Enter employee name:");
		scanf("%s",ptr[j].name);
		__fpurge(stdin);
		printf("Enter salary:");
		scanf("%f",&ptr[j].salary);
		__fpurge(stdin);
		printf("Enter DOB:");
		scanf("%2d-%2d-%5d",&ptr[j].dt.date,&ptr[j].dt.month,&ptr[j].dt.year);
		__fpurge(stdin);
		printf("\n");
	}
}



//-------------------------------------------------------------function definition to swap-------------------------------------------------------------------

void swap(struct employee *ptr1,int n)
{
	struct employee temp;
	int j;
	for(j=0,n=n-1;j<n;j++,n--)
	{
		strcpy(temp.name,ptr1[j].name);
		strcpy(ptr1[j].name,ptr1[n].name);
		strcpy(ptr1[n].name,temp.name);
		temp.salary=ptr1[j].salary;
		ptr1[j].salary=ptr1[n].salary;
		ptr1[n].salary=temp.salary;
		temp.dt=ptr1[j].dt;
		ptr1[j].dt=ptr1[n].dt;
		ptr1[n].dt=temp.dt;
	}
}


//---------------------------------------------------------------------function defintion to display----------------------------------------------------------


void display(struct employee *ptr,int n)
{
	int k;
	for(k=0;k<n;k++)
	{
		printf("\n---------------------------------------Detailes of Employee %d-------------------------------------------------\n",k+1);
		printf("%s\t",ptr[k].name);
		printf("%f\t",ptr[k].salary);
		printf("%d-%d-%d\n",ptr[k].dt.date,ptr[k].dt.month,ptr[k].dt.year);
	}
}
