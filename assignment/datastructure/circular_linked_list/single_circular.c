#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;

void addatbegin(int);
void display();
void delete();
void add_at_last(int);
void delete_at_last();
void search(int);
void create_list(int *,int);

void main()
{
	int num,opt,val,n,i;
	while(1)
	{
		printf("------------------------------------------------------------------------------------\n");
		printf("------------------------------------------------------------------------------------\n");
		printf("MENU :----\n 0.exit\n 1.add at begin\n 2.display\n 3.delete\n 4.add at last\n 5.delete at last\n 6.search\n 7.create list\n 8.delete entire list\n select the menu: ");
		scanf("%d",&opt);
		__fpurge(stdin);

		switch(opt)
		{
			case 0: exit(1);
			case 1: printf("enter the number\n");
				scanf("%d",&num);
				addatbegin(num);
				break;
			case 2: display();
				break;
			case 3: delete();
				break;
			case 4: printf("enter the number\n");
				scanf("%d",&num);
				add_at_last(num);
				break;
			case 5: delete_at_last();
				break;
			case 6: printf("enter the position\n");
				scanf("%d",&num);
				search(num);
				break;
			case 7: printf("enter the no. of elements\n");
				scanf("%d",&n);
				__fpurge(stdin);
				int *ptr=(int *)malloc(n*sizeof(int));
				if(ptr==NULL)
				{
					printf("failed to allocate memory\n");
					exit(1);
				}
				for(i=0;i<n;i++)
				{
					printf("enter the input\n");
					scanf("%d",&ptr[i]);
					__fpurge(stdin);
				}
				create_list(ptr,n);
				break;



			default:printf(" INVALID OPTION SO PLEASE ENTER THE VALID OPTION\n");
		}
	}
}

//------------------------------------------------------------------------------------------

void addatbegin(int num)

{
	struct node *temp;
	struct node*ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;

	if(head==NULL)
	{
		head=ptr;
		ptr->link=ptr;
		return;
	}
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	ptr->link=head;
	//head=temp->link=ptr;
	temp->link=ptr;
	head=ptr;
}


//----------------------------------------------------------------

void display()
{
	struct node *temp;
	int count=0;

	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	temp=head;
	do
	{
		count++;
		printf(" DATA : %d\n",temp->data);
		temp=temp->link;
	}while(temp!=head);

	printf(" NO. OF NODES : %d\n",count);
}


//--------------------------------------------------------------------------------

void delete()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=head->link;
	free(head);
	head=temp->link;
}

//-----------------------------------------------------------------------

void add_at_last(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;

	if(head==NULL)
	{
		printf("list is empty\n");
		head=ptr;
		ptr->link=ptr;
		return;
	}
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	ptr->link=head;
	temp->link=ptr;
}

//--------------------------------------------------------------------------


void delete_at_last()
{
	struct node*temp,*prev,*cur;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	cur=head->link;
	prev=head;
	while(cur->link!=head)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=head;
	free(cur);
}


//----------------------------------------------------------------------------

void search(int num)

{
	struct node *temp;
	int count=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}

	temp=head;
	while(temp->link!=head)
	{
		count++;
		if(temp->data==num)
		{
			printf("element fou nd at : %d\n",count);
			return;
		}
		temp=temp->link;
	}
}

//---------------------------------------------------------------------------


void create_list(int *pptr,int n)
{
	int i;
	struct node *ptr,*temp;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=pptr[i];
		ptr->link=head;
		if(head==NULL)
		{
			head=ptr;
			ptr->link=ptr;
			return;
		}
		temp=head;
		while(temp->link!=head)
		{
			temp=temp->link;
		}

		if(temp->link==head)
		ptr->link=head;
		temp->link=ptr;
	//	head=ptr;
	}
}


































