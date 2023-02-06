#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *front=NULL;
struct node *rear=NULL;
void insert(int);
void delete();
void display();
void count();
void search(int);
void create_list(int *,int);
void delete_list();
void delete_par_node(int);
void delete_duplicate();
//void swap_links(int,int);

void main()
{
	int num,opt,pos,n,i;
	int *pptr;
	while(1)
	{
		printf("MENU:----\n 0.exit\n 1.insert\n 2.delete\n 3.display\n 4.count\n 5.search\n 6.create entire list\n 7.delete entire list\n 8.delete particular node\n 9.delete duplicate node\n 10.swap by links\n enter your option : ");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			
			case 0: exit(0);
			case 1: printf("enter a number\n");
				scanf("%d",&num);
				insert(num);
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: count();
				break;
			case 5: printf("enter the position\n");
				scanf("%d",&pos);
				search(pos);
				break;
			case 6: 
				printf(" enter how many elements\n");
				scanf("%d",&n);
			         __fpurge(stdin);	
				pptr=(int *)malloc(1*sizeof(int));
				if(pptr==NULL)
				{
				printf("failed to allocate memory\n");
				exit(1);
				}
				
				for(i=0;i<n;i++)
				{
					printf("enter the input\n");
					scanf("%d",&pptr[i]);
					__fpurge(stdin);
				}
				create_list(pptr,n);
				break;
			case 7: delete_list();
				break;
			case 8: printf("enter the position where u need to delete\n");
				scanf("%d",&pos);
				delete_par_node(pos);
				break;
			case 9:delete_duplicate();
			       break;
		
				


                                default:printf("invalid input.......\n");
		}
	}
}

//------------------------------------------------

void insert(int num)
{
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->next=NULL;
	if(rear==NULL)
	{
		ptr->prev=NULL;
		front =rear=ptr;
		return;
	}
	ptr->prev=ptr;
	rear->next=ptr;
	rear=ptr;

}
//----------------------------------------------

void delete()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	else if(front->next=NULL)
	{
		free(front);
		front=rear=NULL;
		return;
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
		front->prev=NULL;
	}
}

//-------------------------------------------------

void display()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

//-------------------------------------------------

void count()
{
	struct node *temp;
	int count=0;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		count++;
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("total no. of nodes= %d\n",count);
}

//------------------------------------------------

void search(int pos)
{
	int count=0;
	struct node *temp;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		count++;
		if(temp->data==pos)
		{
			printf("element found at pos: %d\n",count);
			return;
		}
		temp=temp->next;
	}
	printf("element not found\n");
}

//------------------------------------------------------

void create_list(int *pptr,int n)
{
	int i;
	struct node *ptr;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=pptr[i];
			printf("element not found\n");
		ptr->next=NULL;
		if(rear==NULL)
		{
			ptr->prev=NULL;
			rear=front=ptr;
		}
		else
		{
			ptr->prev=rear;
			rear->next=ptr;
			rear=ptr;
		}
	}
}


//-------------------------------------------------------

void delete_list()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	//temp=front;
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		free(temp);
	}
	rear=front;
}

//--------------------------------------------------------------

void delete_par_node(int pos)
{
	struct node *temp;
	if(front==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	if(front->data==pos)
	{
		if(front->next=NULL)
		{
			free(front);
			front=rear=NULL;
		}

		front=front->next;
		free(front->prev);
		front->prev=NULL;
	}


	temp=front;
	while(temp!=NULL)
	{
		if(temp->data==pos)
		{
			temp->prev->next=temp->next;
			if(temp->next!=NULL);
			temp->next->prev=temp->prev;
			free(temp);
			return;
		}
		temp=temp->next;
	}
	printf("no data found\n");
}

//---------------------------------------------------------------

void delete_duplicate()
{
	struct node *p,*q,*temp;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	if(front->next==NULL)
	{
		printf("duplicate not found\n");
		return;
	}
	for(p=front;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data==q->data)
			{
				q->prev->next=q->next;
				if(q->next!=NULL)
					q->next->prev=q->prev;
				else
					rear=q->prev;

				temp=q;
				q=q->prev;
				free(temp);
			}
		}
	}
}
















