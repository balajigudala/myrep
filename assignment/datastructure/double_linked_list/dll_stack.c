#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	struct node *prev;
	int data;
	struct node*next;
};

struct node *head=NULL;
void push(int);
void pop();
void display();
int count();
void addatlast(int);
void deleteatlast();
int search(int);
void reverse_list();
void addafternode(int,int);
void deleteparnode(int);
void create_stack(int *,int);
void delete_entstack();
void duplicate();
void  add_before(int,int);
void selection_sort();
void bubble_sort();

void main()
{
	int num,opt,pos,val;
	while(1)
	{
		printf("menu------>\n 0.exit\n 1.push\n 2.pop\n 3.display\n 4.count\n 5.add at last\n 6.delete at last\n 7.search\n 8.reverse stack\n 9.add after a node\n 10.create stack\n 11.delete entire stack\n 12.delete duplicate stack\n 13.delete particular stack\n 14.add before a stack\n 15.sorting\n enter ur option:");

		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("enter the number\n");
			       scanf("%d",&num);
			       push(num);
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:int res;
			       res=count();
			       printf("%d\n",res);
			       break; case 5:printf("enter the number\n");
			       scanf("%d",&num);
			       addatlast(num);
			       break;
			case 6:deleteatlast();
			       break;
			case 7:int result;
			       printf("enter the data to be searched\n");
			       scanf("%d",&pos);
			       result=search(pos);
			       if(result==-1)

				       printf("no data found\n");
			       else

				       printf("data found at:%d\n",result);


			       break;
			case 8:reverse_list();
			case 9:printf("enter a num and val\n");
			       scanf("%d %d",&num,&val);
			       addafternode(num,val);
			       break;
			
			case 10:int i,n;
				int *iptr;
				printf("enter the no. of data elements to be added\n");
				scanf("%d",&n);
				iptr=(int *)malloc(1*sizeof(int));
				if(iptr==NULL)
				{
					printf("failed to allocate memory\n");
					exit(1);
				}
				for(i=0;i<n;i++)
				{
					printf("enter the input\n");
					scanf("%d",&iptr[i]);
				}
				create_stack(iptr,n);
				free(iptr);
				break;

			case 11:delete_entstack();
				break;
			case 12:duplicate();
				break;
			case 13:printf("enter the no. to be searched\n");
				scanf("%d",&num);
				deleteparnode(num);
				break;
			case 14:printf("enter the no.to be searched\n"); 
				scanf("%d",&num);
				printf("enter the data\n");
				scanf("%d",&val);
				add_before(num,val);
				break;
			case 15:printf("---------------sorting--------------------------");
				int opt1;
				printf("MENU-----\n  1.selection sort\n  2.bubble sort\n");
				scanf("%d",&opt1);
				switch(opt1)
				{
					char subopt;
					case 1:printf("SUB--MENU-----\n    a.sort by data\n    b. sort by address or link\n");
					       __fpurge(stdin);
					       scanf("%c",&subopt);
					       switch(subopt)
					       {
						       case 'a':selection_sort();
								break;
						      /* case 'b':selection_sort_link();
								break;*/
					       }
					case 2:printf("SUB--MENU-----\n    a.sort by data\n    b. sort by address or link\n");

					       __fpurge(stdin);
					       scanf("%c",&subopt);
					       switch(subopt)
					       {
						       case 'a':bubble_sort();
								break;

						       /*case 'b':bubble_sort_link();
								break;*/




						       default:printf("--------------enter a valid input---------------\n");





					       }
				}
		}
	}
}

//function definations................

void create_stack(int *iptr,int n)
{
	int i;
	struct node *ptr;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=iptr[i];
		ptr->prev=0;
		ptr->next=head;

		if(head!=0)
			ptr->next->prev=ptr;
		head=ptr;
	}
}


void push(int num)
{
	struct node*ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory\n");
		exit(1);
	}
	ptr->data=num;
	ptr->prev=0;
	ptr->next=head;
	if(head!=0)
	{
		ptr->next->prev=ptr;    // head->prev=ptr;
	}
	head=ptr;
}

void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}


void pop()
{
	struct node *temp;
	if(head==0)
	{
		printf("list is empty\n");
		return;
	}
	if(head->next==0)
	{
		free(head);
		head=0;
				return;
			}
			temp=head;
			head=head->next;
			head->prev=0;
			free(temp);
		}


		int count()
		{
			struct node *temp;
			int count=0;
			temp=head;
			if(head==NULL)
			{
				printf("list is empty\n");
				return 1;
			}
			while(temp!=NULL)
			{
				printf("%d\n",temp->data);
				temp=temp->next;
				count++;
			}
			return count;
		}

		void addatlast(int num)
		{
			struct node *ptr,*temp;
			ptr=(struct node *)malloc(1*sizeof(struct node));
			ptr->data=num;
			ptr->next=NULL;
			if(head==NULL)
			{
				ptr->prev=NULL;
				head=ptr;
				return;
			}
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
		}

		void deleteatlast()
		{
			struct node *temp;
			if(head==NULL)
			{
				printf("list is empty\n");
				return;
			}
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			if(head->next!=NULL)
				temp->prev->next=NULL;
			else
				head=NULL;
			free(temp);
		}


		int search(int pos)
		{
			struct node *temp;
			int c=0;
			if(head==NULL)
			{
				printf("list is empty\n");
				return 0;
			}
			temp=head;
			while(temp!=NULL)
			{
				c++;
				if(temp->data==pos)

					return c;
				temp=temp->next;
			}
			return(-1);
		}

		void reverse_list()
		{
			struct node *temp,*cur,*nxt;
			if(head==0)
			{
				printf("list is empty\n");
				return;
			}
			cur=head;
			while(cur!=0)
			{
				nxt=cur->next;
				temp=cur->prev;
				cur->prev=cur->next;
				cur->next=temp;
				if(cur->prev==0)
					head=cur;
				cur=nxt;
			}
		}


		void addafternode(int num,int val)
		{
			struct node *ptr,*temp;
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
					ptr=(struct node*)malloc(1*sizeof(struct node));
					ptr->data=val;
					ptr->prev=temp;
					ptr->next=temp->next;
					temp->next=ptr;
					return;
				}
				temp=temp->next;
			}
			printf("element not found\n");
		}

		void delete_entstack()
		{
			struct node*temp;
			if(head==NULL)
			{
				printf("list is empty\n");
				return;
			}

			while(head!=NULL)
			{
				temp=head;

				head=head->next;
				free(temp);
			}
			printf("elements in the list are deleted\n");

		}


		void duplicate()
		{
			struct node *p,*q,*temp;
			if(head==0)
			{
				printf("list is empty\n");
				return;
			}
			for(p=head;p!=0;p=p->next)
			{
				for(q=p->next;q!=0;q=q->next)
				{
					if(p->data=q->data)
					{
						temp=q;
						q->prev->next=q->next;
						if(q->next!=0)
							q->next->prev=q->prev;
						q=q->prev;
						free(temp);
					}
				}
			}
		}

		void deleteparnode(int num)
		{
			struct node *temp;
			if(head==0)
			{
				printf("list is empty\n");
				return;
			}
			if(head->data==num)
			{
				if(head->next==0)
				{
					free(head);
					head=0;
					return;
				}
				temp=head;
				head=head->next;
				head->prev=0;
				free(temp);
				return;
			}

			temp=head->next;
			while(temp!=0)
			{
				if(temp->data==num)
				{
					temp->prev->next=temp->next;
					if(temp->next!=0)
						temp->next->prev=temp->prev;
					free(temp);
					return;
				}
				temp=temp->next;
			}
			printf("element not found\n");
		}


		void add_before(int num,int val)
		{
			struct node *temp;
			if(head==NULL)
			{
				printf("list is empty\n");
				return;
			}
			if(head->data==num)
			{
				//struct node*temp;
				struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
				if(ptr==NULL)
				{
					exit(1);
				}

				ptr->data=val;
				ptr->next=head;
				ptr->prev=NULL;

				head=ptr;
			}

			temp=head;
			while(temp!=NULL)
			{
				if(temp->data==num)
				{
					struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
					if(ptr==NULL)
					{
						exit(2);
					}
					ptr->data=val;
					ptr->next=temp;
					ptr->prev=temp->prev;
					temp->prev=ptr;
					ptr->prev->next=ptr;
					return;
				}
				temp=temp->next;
			}


			printf("element not found\n");
		}


		//...................... SORTINGS....................

		void selection_sort()
		{
			int temp;
			struct node *p,*q;
			if(head==NULL)
			{
				printf("list is empty\n");
				return;
			}
			for(p=head;p->next!=NULL;p=p->next)
			{
				for(q=p->next;q!=NULL;q=q->next)
				{
					if(p->data>q->data)
					{
						temp=p->data;
						p->data=q->data;
						q->data=temp;
					}
				}
			}
		}


		// bubble sort using exchange by data......

		void bubble_sort()
		{
			struct node *p,*q,*e;
			int temp;
			if(head==NULL)
			{
				printf("List is empty\n");
				return;
			}
			for(e=NULL;head->next!=e;e=q)
			{
				for(p=head;p->next!=e;p=p->next)
				{
					q=p->next;
					if(p->data > q->data)
					{
						temp=p->data;
						p->data=q->data;
						q->data=temp;
					}

				}
			}
		}





















































