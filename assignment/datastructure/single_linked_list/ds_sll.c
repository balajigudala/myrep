#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node*link;
};

void addatbeg(int num);
void deleteatbeg();
void display();
int count();
int search(int num);
void del_ent_list();
void add_at_last(int);
void delete_at_last();
void add_after_a_node(int,int);
void delete_particular_node(int num);

struct node*head=NULL;

void main()
{
	int num,pos,opt,val;
	while(1)
	{
		printf(".............................................................................................................................................\n");
		printf(" MENU \n 0.exit\n 1.add at begin\n 2.delete at begin\n 3.display\n 4.count no. of nodes\n 5.search or position\n 6. delete entire list\n 7.add at last\n 8.delete at last\n 9.add after a node\n 10. delete particular node\n 11.add before a node\n 12.reverse the list\n enter your option:");
		scanf("%d",&opt);
		__fpurge(stdin);

		switch(opt)
		{
			case 0: exit(0);

			case 1: printf("enter the data\n");
				scanf("%d",&num);
				addatbeg(num);
				break;

			case 2: deleteatbeg();
				break;

			case 3: display();
				break;

			case 4: int s;
				s=count();
				printf("%d\n",s);
				break;

			case 5: int res;
				printf("enter the data to be searched : ");
				scanf("%d",&pos);
				res=search(pos);
				if(res==-1)
				{
					printf("no data found\n");
				}
				else
				{

					printf("data found at : %d\n",res);
				}
				break;

			case 6:del_ent_list();
			       break;

			case 7:printf("enter the input\n");
			       scanf("%d",&num);
			       add_at_last(num);
			       break;

			case 8:delete_at_last();
			       break;

			case 9: printf("enter the inputs\n");
				scanf("%d %d",&num,&val);
				add_after_a_node(num,val);
				break;
			case 10:printf("enter the input\n");
				scanf("%d",&num);
				delete_particular_node(num);
				break;







		}
	}
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<[ DEFINATIONS OF THAT FUNCTIONS ]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


//............................... defination of add at begining..........................

void addatbeg(int num)
{
	struct node*ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("failed to allocate memory\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}

// .......................delete at begining.................................

void deleteatbeg()
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

//............................display........................

void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		printf(".....................................\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}


//......................count no. of nodes......................


int count()
{
	struct node *temp;
	int c=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		printf(".....................................\n");
		return 1;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
		c++;
	}
	return c;
}

//.........................search data from node................

int search(int pos)
{
	struct node *temp;
	int c=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		printf(".....................................\n");
		return 1;
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		if(pos==temp->data)
			return c;

		temp=temp->link;
	}
	return (-1);

}

//..............................delete entire list...........................

void del_ent_list()
{

	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		printf(".....................................\n");
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

//........................add at last................................

void add_at_last(int num)
{
	struct node *temp;
	struct node*ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=NULL;

	if(head==NULL)                   //...........when list is empty................
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)         //..............list contains nodes...............
	{
		temp=temp->link;
	}
	temp->link=ptr;
}



//........................delete at last....................

void delete_at_last()
{
	if(head==NULL)                                             // list is empty.........
	{
		printf("list is empty\n");
		printf(".....................................\n");
		return ;
	}
	if(head->link==NULL)                          // list contains single node and also verified the first node............
	{
		free(head);
		head=NULL;
		return;
	}
	struct node *prev,*cur;
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


//...................add after a node..................................


void add_after_a_node(int num,int val)
{
	struct node *temp,*ptr;
	if(head==NULL)                                 //************ when list is empty***********

	{
		printf("list is empty\n");
		printf(".....................................\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			ptr->data=val;
			ptr->link=temp->link;
			temp->link=ptr;
			return;
		}
		temp=temp->link;
	}
	printf("element not found\n");
}

//...............delete particular node.........................

void delete_particular_node(int num)
{
	struct node *prev,*cur;
	if(head==NULL)
	{
		printf("list is empty\n");
		printf(".....................................\n");
		return ;
	}
	if(head->data==num)
	{
		if(head->link==NULL)
		{
			free(head);
			head=NULL;
			return ;
		}
		cur=head;
		head=head->link;
		free(cur);
		return ;
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
	printf("element is not found\n");
}
















