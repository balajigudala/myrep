#include<stdlib.h>
#include<stdio_ext.h>
#include<stdio.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void display();
void insert(int);
void del_last();
void add_beg(int);
void del_beg();
void del_list();
void crt_list(int *a,int num);
void count();
void del_part(int num);
void del_dup();
void main()
{
	int opt,num,i,*ptr;
	while(1)
	{
	printf("1)add at last\n2)display\n3)delete at last\n4)add at begining\n5)delete at begining\n6)delete lis\n7)create list\n8)count\n9)delete particular node\n10)delete duplicate nodes\n");
	printf("select an operation to be perfromed\n");
	scanf("%d",&opt);
	__fpurge(stdin);
	switch(opt)
	{
		case 0:
			exit(1);
		case 1:
			printf("enter the number to be added\n");
			scanf("%d",&num);
			__fpurge(stdin);
			insert(num);
			break;
		case 2:
			display();
			break;
		case 3:
			del_last();
			break;
		case 4:
			printf("enter the value to be added\n");
			scanf("%d",&num);
			__fpurge(stdin);
			add_beg(num);
			break;
		case 5:
			del_beg();
			break;
		case 6:
			del_list();
			break;
		case 7:
			printf("enter the size of the list \n");
			scanf("%d",&num);
			__fpurge(stdin);
			ptr=(int *)malloc(num*sizeof(int));
			if(ptr==NULL)
			{
				printf("failed to allocate memory\n");
				exit(1);
			}
			for(i=0;i<num;i++)
			{
				printf("enter the values\n");
				scanf("%d",&ptr[i]);
				__fpurge(stdin);
			}
			crt_list(ptr,num);
			break;
		case 8:
			count();
			break;
		case 9:
			printf("enter the node you want to delete\n");
			scanf("%d",&num);
			__fpurge(stdin);
			del_part(num);
			break;
		case 10:
			del_dup();
			break;
	}
	}
}
void del_dup()
{
	struct node *temp,*p,*q;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	for(p=head;p->next!=head;p=p->next)
	{
		for(q=p->next;q!=head;q=q->next)
		{
			if(p->data == q->data)
			{
				q->prev->next=q->next;
				if(q->next!=head)
					q->next->prev=q->prev;
				else
					head->prev=q->prev;
				temp=q;
				q=q->prev;
				free(temp);
			}
		}
	}
}

//----------------------------------------------------
void del_part(int num)
{
	struct node *temp,*temp1;;
	if(head==NULL)
	{
		printf("list is empty\n");
		return ;
	}
	temp=head;
	do{
		if(temp->data == num)
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			if(temp==head)
			{
				temp1=temp;
				head=temp->next;
				free(temp1);
				return;
			}
			free(temp);
		}
		temp=temp->next;
	}while(temp!=head);
}


//-------------------------------------------
void count()
{
	int c=0;
	struct node *temp;
        if(head==NULL)
        {
                printf("list is empty\n");
                return;
        }
        temp=head;
        do
        {
		c++;
                printf("data:%d\n",temp->data);
                temp=temp->next;
        }while(temp!=head);
	printf("count:%d\n",c);
}

//------------------------------------------------------
void crt_list(int *a,int num)
{
	struct node *ptr;
	int i;
	for(i=0;i<num;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate memory\n");
			exit(1);
		}
		ptr->data=a[i];
        if(head==NULL)
        {
                ptr->next=ptr;
                ptr->prev=ptr;
                head=ptr;
        }
        else
        {
                ptr->prev=head->prev;
                ptr->next=head;
                head->prev->next=ptr;
                head->prev=ptr;
        }
	}
}

//---------------------------------------
void del_list()
{
	struct node *temp,*temp1;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	do
	{
		temp1=temp;
		if(temp->next!=NULL)
			temp=temp->next;
		free(temp1);
	}while(temp!=head);
	head=NULL;
}

//---------------------------------------------------------------
void del_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->next == head)
	{
		free(head);
		head=NULL;
	}
	else
	{
		temp=head;
		head=temp->next;
		temp->prev->next=temp->next;
		head->prev=temp->prev;
		free(temp);
	}
}
//--------------------------------------------------------------
void add_beg(int num)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory\n");
		exit(1);
	}
	ptr->data=num;
	if(head==NULL)
	{
	ptr->next=ptr;
	ptr->prev=ptr;
	head=ptr;
	return;
	}
	else
	{
	ptr->next=head;
	ptr->prev=head->prev;
	head->prev->next=ptr;
	head->prev=ptr;
	head=ptr;
	}
}

//-----------------------------------------------
void del_last()
{
	struct node *temp,*temp1;
	if(head==NULL)
	{
		printf("list is empty\n");
		return ;
	}
	if(head->next==head)
	{
		free(temp);
		head=NULL;
		return;
	}
	else
	{
		temp=head->prev;
		temp->prev->next=head;
		head->prev=temp->prev;
		free(temp);
	}
		
}

//------------------------------------------------------
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	do
	{
		printf("data:%d\n",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

//----------display----------------------
void insert(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory\n");
		exit(1);
	}
	ptr->data=num;
	if(head==NULL)
	{
		ptr->next=ptr;
		ptr->prev=ptr;
		head=ptr;
		return ;
	}
	else
	{
		ptr->prev=head->prev;
		ptr->next=head;
		head->prev->next=ptr;
		head->prev=ptr;
	}
}
