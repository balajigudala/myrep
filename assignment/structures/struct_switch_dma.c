#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>

int i=0,j=0;

struct book *memory_alloc();
void read(struct book *ptr);
void swap(struct book *s1,struct book *s2);
void display(struct book *ptr);
void memory_dealloc(struct book *ptr);

struct book
{
	char name[32];
	int nop;
	float price;
};

struct book_ops
{
	struct book*(*f_memory_alloc)();
	void(*f_read)(struct book*);
	void(*f_swap)(struct book*,struct book*);
	void(*f_display)(struct book*);
	void(*f_memory_dealloc)(struct book*);
};

	void main()
	{
		struct book *b1,*b2;
		struct book_ops op;
		int  opt;

		op.f_read=read;
		op.f_swap=swap;
		op.f_display=display;
		op.f_memory_dealloc=memory_dealloc;

		while(1)
		{
			printf("menu:\n 0.exit\n 1.memory_allocation\n 2.read\n 3.swap\n 4.display\n 5.memory_deallocation\n enter your option:\n");
			scanf("%d",&opt);
			__fpurge(stdin);
			switch(opt)
			{


				case 0: exit(1);


				case 1:i++;
				       b1=memory_alloc();
				       b2=memory_alloc();
				       if((b1==NULL)||(b2==NULL))
				       {
					       printf("-----------failed to allocate memory------------\n");
					       exit(1);
				       }
				       break;


				case 2:j++;
				       if(i==j)
				       {
				       op.f_read(b1);
				       op.f_read(b2);
				       }
				       else
					       printf("<<<<<<<<<<<<--- first allocate the memory and nxt read the inputs --->>>>>>>>>>>>\n");
				       break;


				case 3:op.f_swap(b1,b2);
				       break;


				case 4:/*if(j==1)
				       {
					       op.f_display(b1);
					       op.f_display(b2);
					       break;
				       }*/
				       if(j==0)
				       
				       {
					       printf("\n");
					       printf("---------------*no memory is read*--------------------\n");
					       break;
				       }
				       if(i==0)
				       {
					       printf("<<<<<<<<<<<<<<--memory allocation is not yet done-->>>>>>>>>>>>>>>\n");
				      break; 
				       } 
				       
				       if(j==1)
				       {
					       op.f_display(b1);
					       op.f_display(b2);
					       break;
				       }


				case 5:
				       if(i==1)
				       {
					       op.f_memory_dealloc(b1);
					       op.f_memory_dealloc(b2);
					       i--;
					       printf("----------memory deallcation is done-----------\n");
					       break;
				       }
				       else
				       {
					       printf("\n");
					       printf("----------memory is not allocated----------------\n");
				       }
				       

				       break;
				
				default: printf("-----------musuk kurchooo ra pula chokkaa-----------\n");


			        }
		}
	}
		
	









/*	b1=memory_alloc();
	b2=memory_alloc();
	if((b1==NULL)||(b2==NULL))
		exit(1);
	read(b1);
	read(b2);
	swap(b1,b2);
	display(b1);
	display(b2);
	memory_dealloc(b1);
	memory_dealloc(b2);
}*/



struct book *memory_alloc()
{
	struct book *ptr=(struct book *)malloc(1*sizeof(struct book));
	return ptr;
}




void read(struct book *ptr)
{
	printf("enter book name:");
	scanf("%s",ptr->name);
	__fpurge(stdin);
	printf("enter page num:");
	scanf("%d",&ptr->nop);
	__fpurge(stdin);
	printf("enter price:");
	scanf("%f",&ptr->price);
	__fpurge(stdin);
}




void swap(struct book *s1,struct book *s2)
{
	struct book temp;
	strcpy(temp.name,s1->name);
	{
		struct book temp;
		strcpy(temp.name,s1->name);
		strcpy(s1->name,s2->name);
		strcpy(s2->name,temp.name);

		temp.nop=s1->nop;
		s1->nop=s2->nop;
		s2->nop=temp.nop;

		temp.price=s1->price;
		s1->price=s2->price;
		s2->price=temp.price;
	}
}





void display(struct book *ptr)
{
	printf("%p--------------%s\n",ptr->name,ptr->name);
	printf("%p--------------%d\n",&ptr->nop,ptr->nop);
	printf("%p------------- %f\n",&ptr->price,ptr->price);
}





void memory_dealloc(struct book *ptr)
{
	free(ptr);
}
