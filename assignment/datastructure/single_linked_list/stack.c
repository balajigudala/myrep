// single linked list operations......
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
void push(int);
void pop();
void delete_en_stack();
void display();
int search(int);
int count();
//void add_at_last(int);
//void delete_last();
void del_par_node(int);
//void add_after_node(int,int);
//void add_before_node(int,int);
void reverse_list();
void create_stack(int *,int );
void swap_data(int ,int );
void swap_byadress(int,int);

struct node
{
	int data;
	struct node *link;
};
struct node *head = NULL;
void main()
{
	int num,pos,opt;
	while(1)
	{
		printf("---*menu*---\n0.exit\n1.push\n2.pop\n3.display\n4.delte entire stack\n5.search\n6.count\n7.delete a par stack\n8.reverse stack\n9.create stack\n10.swap by data\n11.swap by adress\n");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case 0:exit(0);
			       break;
			case 1:printf("enter the data\n");
			       scanf("%d",&num);
			       push(num);
			       break;
			case 2:
			       pop();
			       break;
			case 3:display();
			       break;
			case 4:
			       delete_en_stack();
			       break;
			case 5:
			       printf("enter the value to be search\n");
			       __fpurge(stdin);
			       int res,n1;
			       scanf("%d",&n1);
			      res= search(n1);
			       if(res==-1)
				       printf("no data found::::::: :-)\n");
			       else
			       printf("data found at %d\n",res);
			       break;
			case 6:
			       {
			       int res1;
			       res1=count();
			       printf("count is %d\n",res1);
			       break;
			       }
	/*		case 7:printf("enter the data\n");
			       __fpurge(stdin);
			       scanf("%d",&num);
			       add_at_last(num);
			       break;
			case 8:
			       delete_last();
			       break;
			case 9:{
			       int num,res;
			       printf("enter the num's\n");
			       scanf("%d-%d",&num,&res);
			       add_after_node(num,res);
				       break;
			       }*/
			case 7:printf("enter the num\n");
			       scanf("%d",&num);
			       del_par_node(num);
			       break;
		/*	case 11:{
                               int num,res;
                               printf("enter the num's\n");
                               scanf("%d-%d",&num,&res);
                               add_before_node(num,res);
                                       break;
                               }*/
			case 8:
				reverse_list();
				break;
			case 13:{
				int i,n1;
				int *ptr;
				printf("enter how many elements\n");
				scanf("%d",&n1);
				ptr=(int *)malloc(n1 *sizeof(int));
				if(ptr==NULL)
				{
					printf("failed to allocate memory in heap segment\n");
					exit(1);
				}
				for(i=0;i<n1;i++)
				{
					printf("enter the i/p\n");
					scanf("%d",&ptr[i]);
				}
				create_stack(ptr,n1);
				free(ptr);
				break;
				}
			

			case 10:{
				int num,val;
				printf("enter the data\n");
				__fpurge(stdin);
				scanf("%d-%d",&num,&val);
				swap_data(num,val);
				break;
				}

			case 11:{
				int num,val;
                                printf("enter the data\n");
                                __fpurge(stdin);
                                scanf("%d-%d",&num,&val);
                                swap_byadress(num,val);
				break;
				}
		}
	}
}

void create_stack(int *iptr,int n )
{
	int i;
	struct node*ptr;
	for(i=0;i<n;i++)
	{
ptr=(struct node*)malloc(1*sizeof(struct node*));
		ptr->data=iptr[i];
		ptr->link=head;
		head=ptr;
	}
}



void swap_byadress(int num,int val)
{
	int pos1=0,pos2=0;
	struct node* p,*q,*r,*s,*temp;
	if(head==NULL)
	{
		printf("linkedlist is empty");
		return;
	}
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num)
			break;
		r=p;
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==val)
			break;
		s=q;
		q=q->link;
	}
	if((p==NULL)||(q==NULL))
	{
		printf("element not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
		temp=r;
		r=s;
		s=temp;
	}
	if(p->link!=q)
	{              
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=head)
			r->link=q;
		else
			head=q;
		s->link=p;
		return;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p!=head)
			r->link=q;
		else
			head=q;
		return;
	}
}
void swap_data(int num,int val)
{
	int temp;
	struct node *p1,*p2;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	p1=p2=head;
	while(p1!=NULL)
	{
		if(p1->data==num)
			break;
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		if(p2->data==val)
			break;
		p2=p2->link;
	}
	if((p1==NULL)||(p2==NULL))
	{
		printf("data not found\n");
		return;
	}
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}

/*void create_list(int *iptr,int n1)
{
	int i;
	struct node *ptr,*start=NULL,*prev,*temp;
	for(i=0;i<n1;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate\n");
			exit(2);
		}
		ptr->data=iptr[i];
		ptr->link=NULL;
		if(start==NULL)
			start=ptr;
		else 
			prev->link=ptr;
		prev=ptr;
	}
	if(head==NULL)
	{
		head=start;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=start;*/


void push(int num)
{
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
/*void add_before_node(int num,int val)
{
	struct node *prev,*cur,*ptr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==num)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("failed to allocate\n");
			exit(1);
		}
		ptr->data=val;
		ptr->link=head;
		head=ptr;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("failed to allocate\n");
				exit(1);
			}
			ptr->data=val;
			ptr->link=cur;
			prev->link=ptr;
			return;
		}

		prev=cur;
		cur=cur->link;

	}
	printf("element is not found\n");
	return;
}*/
void pop()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	head=head->link;
	free(temp);
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}
void delete_en_stack()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		head=head->link;
		free(temp);
		temp=head;
	}
}
int search(int n1)
{
	int c=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return(-2);
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		if(n1==temp->data)
			return c;
		temp=temp->link;
	}
	return(-1);
}
int count()
{
	int c=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return(-2);
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return(c);
}
/*void add_at_last(int num)
{
	struct node *temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=ptr;
}*/
void del_par_node(int num)
{
	struct node *prev,*cur;
	if(head==NULL)
	{
		printf("elementi n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
		cur=head;
		head=head->link;
		free(cur);
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			prev->link=cur->link;
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->link;
	}
	printf("element not found\n");
}
/*void delete_last()
{
	struct node *prev,*cur;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	free(cur);
	prev->link=NULL;
}
void add_after_node(int num,int val)
{
	struct node *temp,*ptr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			ptr->data=val;
			ptr->link=temp->link;
			temp->link=ptr;
			return ;
		}
		temp=temp->link;
	}
	printf("element is not found\n");
	return;
}*/
void reverse_list()
{
	struct node *prev,*cur,*next;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	prev=NULL;
	cur=head;
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
}
