// single linked list operations......
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

//----------------------[ function declarations ]--------------------------------

void add_at_beg(int);
void del_at_beg();
void delete_en_list();
void display();
int search(int);
int count();
void add_at_last(int);
void delete_last();
void del_par_node(int);
void add_after_node(int,int);
void add_before_node(int,int);
void reverse_list();
void create_list(int *,int );
void swap_data(int ,int );
void swap_byadress(int,int);
void selection_sort();
void selection_sort_link();
void bubble_sort();
void bubble_sort_link();

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

		printf("---*menu*---\n0.exit\n1.add at begi\n2.delete at begi\n3.display\n4.delte entire list\n5.search\n6.count no.of nodes\n7.add_at_last\n8.delete at last\n9.add_after a node\n10.delete a par node\n11.add before a node\n12.reverse list\n13.create list\n14.swap by data\n15.swap by adress\n16.sort\n");
		scanf("%d",&opt);

		__fpurge(stdin);
		switch(opt)
		{
			case 0:exit(0);
			       break;
			case 1:printf("enter the data\n");
			       scanf("%d",&num);
			       add_at_beg(num);                                //......................add at begining.....................
			       break;
			case 2:
			       del_at_beg();
			       break;                                           //...................delete at begining....................
			case 3:display();
			       break;                                         //................. display.....................................
			case 4:
			       delete_en_list();
			       break;                                       //..................delete entire list............................
			case 5:
			       printf("enter the value to be search\n");
			       __fpurge(stdin);
			       int res,n1;
			       scanf("%d",&n1);                              //.....................search.................................
			       res= search(n1);
			       if(res==-1)
				       printf("no data found::::::: :-)\n");
			       else
				       printf("data found at %d\n",res);
			       break;
			case 6:
			       {
				       int res1;
				       res1=count();                                    //..........................count.............................
				       printf("count is %d\n",res1);
				       break;
			       }
			case 7:printf("enter the data\n");
			       __fpurge(stdin);
			       scanf("%d",&num);
			       add_at_last(num);                               //..........add at last......................................
			       break;
			case 8:
			       delete_last();                                  //...................delete at last.........................
			       break;
			case 9:{
				       int num,res;
				       printf("enter the num's\n");
				       scanf("%d-%d",&num,&res);
				       add_after_node(num,res);                        //....................add after a node..........................
				       break;
			       }
			case 10:printf("enter the num\n");
				scanf("%d",&num);
				del_par_node(num);                               // .......................delete particular node................
				break;
			case 11:{
					int num,res;
					printf("enter the num's\n");
					scanf("%d-%d",&num,&res);
					add_before_node(num,res);
					break;
				}
			case 12:
				reverse_list();                                    //*********************[reverse list]****************************
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
					for(i=0;i<n1;i++)                                                       //----------------create list----------------------------
					{
						printf("enter the i/p\n");
						scanf("%d",&ptr[i]);
					}
					create_list(ptr,n1);
					free(ptr);
					break;
				}
			case 14:{
					int num,val;
					printf("enter the data\n");
					__fpurge(stdin);
					scanf("%d-%d",&num,&val);                                     //------------------------------swap_list-------------------------------
					swap_data(num,val);
					break;
				}

			case 15:{
					int num,val;
					printf("enter the data\n");
					__fpurge(stdin);
					scanf("%d-%d",&num,&val);                                     //======================[ swap_address ]======================================
					swap_byadress(num,val);
					break;
				}
			case 16:int opt1;
				printf("MENU-----\n  1.selection sort\n  2.bubble sort\n  3.merge sort\n");
				scanf("%d",&opt1);
				switch(opt1)
				{
					char subopt;
					case 1:printf("SUB--MENU-----\n    a.sort by data\n    b. sort by address or link\n");
					       __fpurge(stdin);
					       scanf("%c",&subopt);
					       switch(subopt)
					       {
						       case 'a':selection_sort();                                         //.............................[[ SORTING ]]............................
								break;
						       case 'b':selection_sort_link();
								break;
					       }
					case 2:printf("SUB--MENU-----\n    a.sort by data\n    b. sort by address or link\n");

					       __fpurge(stdin);
					       scanf("%c",&subopt);
					       switch(subopt)
					       {
						       case 'a':bubble_sort();
								break;
						       case 'b':bubble_sort_link();
								break;
					       }
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
	for(e=NULL;head->link!=e;e=q)
	{
		for(p=head;p->link!=e;p=p->link)
		{
			q=p->link;
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}

		}
	}
}



// bubble sort using exchange by links.......


void bubble_sort_link()
{
	struct node *e,*p,*q,*r,*s,*temp;
	for(e=NULL;head->link!=e;e=q)
	{
		for(r=p=head;p->link!=e;r=p,p=p->link)
		{
			q=p->link;
			if(p->data>q->data)
			{
				p->link=q->link;
				q->link=p;
				if(p!=head)
					r->link=q;
				else
					head=q;

				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}



// selection sort using exchange by data---------

void selection_sort()
{
	int temp;
	struct node *p,*q;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	for(p=head;p->link!=NULL;p=p->link)
	{
		for(q=p->link;q!=NULL;q=q->link)
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


// selection sort using exchange by address........		

void selection_sort_link()
{
	struct node *p,*q,*r,*s,*temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}

	for(r=p=head;p->link!=NULL;r=p,p=p->link)
	{
		for(s=q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data>q->data)
			{
				temp=p->link;
				p->link=q->link;
				q->link=temp;

				if(p!=head)

					r->link=q;
				else
					head=q;

				s->link=p;

				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}






//.................swap by addresss................

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

//--------swap by data---------



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

//-----------------create list........................


void create_list(int *iptr,int n1)
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
	temp->link=start;

}

//----- add at begining.................

void add_at_beg(int num)
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


//------ add before a node.................

void add_before_node(int num,int val)
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
}


// ------- delete at begining....................................

void del_at_beg()
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


//----------display--------------------

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

//------delete entire list........................

void delete_en_list()
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


//-----------search--------------------------------

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

//------------------------ count-------------------------------------------

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

// ----------------------add at last---------------------------------------------

void add_at_last(int num)
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
}
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
//--------------------delete at last------------------------------------------	

void delete_last()
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

//-----------------------add after a node------------------------------------------------------------------

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
}


//--------------------reverse list----------------------------------------

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
