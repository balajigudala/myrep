#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>


struct node
{
	struct node *prev;
	int data;
	int priority;
	struct node *next;
};


struct node *head=NULL;
void insert(int,int);
void display();
void display2();
void delete_ent();
void create_list(int *,int *,int);
void delete_prii(int);
void delete_data_pri(int,int);
void delete_first_pri(int);
void selectionsort_data();
void selectionsort_link();

void main()
{
	int num,pr,opt,n,i;
	int *ptr,*prp;
	char opt2,opt3,opt4;
	while(1)
	{

		printf("-----------------------------------------------------------------------------------------------------\n");

		printf("menu:--\n -2.CLEAR\n -1.POWWER OFF\n  0.EXIT\n  1.INSERT\n  2.DISPLAY\n  3.DELETE\n  4.CREATE LIST\n  5.SORTING  \nenter your option : ");
		scanf("%d",&opt);
		__fpurge(stdin);

		switch(opt)
		{
			case -2:system("clear");
				break;
			
			case -1:system("POWER OFF");
				break;
			
			case 0: exit(0);
			
			
			case 1: printf("enter the data\n");
				scanf("%d",&num);
				__fpurge(stdin);
				printf("enter the priority value\n");
				scanf("%d",&pr);
				insert(num,pr);
				break;
			
			
			
			case 2: printf("    a.display the total node\n    b.display priority based node\n    enter ur option : ");
				scanf("%c",&opt2);
				__fpurge(stdin);
				switch(opt2)
				{
					case 'a': display();
						  break;
					case 'b': 
						  scanf("%d",&pr);
						  display2(pr);
						  break;
				}
				break;
			
			
			
			case 3: while(1)
				{
					printf("-------------------------------------------------------------------------------------------------------------\n");

					printf("    q.QUIT\n    a.DELETE ENTIRE QUEUE\n    b.DELETE USING PRIORITY\n    c.DELETE USING PRIORITY AND DATA\n    d.POP USING PRIORITY\n    enter your option: ");
					__fpurge(stdin);
					scanf("%c",&opt3);
					if(opt3=='q')
					break;
					switch(opt3)
					{
						
						case 'a': delete_ent();
							  break;
						case 'b': printf("enter the priority\n");
							  scanf("%d",&pr);
							  __fpurge(stdin);
							  delete_prii(pr);
							  break;
						case 'c': printf("enter the data and priority\n");

							  scanf("%d %d",&num,&pr);
							  __fpurge(stdin);
							  delete_data_pri(num,pr);
							  break;

						case 'd': printf("enter the priority\n");
							  scanf("%d",&pr);
							  __fpurge(stdin);
						  delete_first_pri(pr);
						  break;
				}
				}
				break;



			case 4: printf("enter the list size\n");
				scanf("%d",&n);
				__fpurge(stdin);
				ptr=(int *)malloc(n*sizeof(int));
				prp=(int *)malloc(n*sizeof(int));

				if((ptr==NULL)||(prp==NULL))
				{
					printf("failed to allocate memory\n");
					exit(1);
				}
				for(i=0;i<n;i++)
				{
					printf("enter the data in the list\n");
					scanf("%d",&ptr[i]);
					__fpurge(stdin);
					printf("enter the priority in the list\n");
					scanf("%d",&prp[i]);
					__fpurge(stdin);
				}
				create_list(ptr,prp,n);
				break;
			
			
			case 5: printf("  a. SWAP BY DATA[SELECTION SORT]\n  b. SWAP BY LINKS [SELECTION SORT]\n  select your option :");
				scanf("%c",&opt4);
				__fpurge(stdin);
				switch(opt4)
				{
					case 'a': selectionsort_data();
						  break;
					case 'b': selectionsort_link();
						  break;
				}
				break;




			default:printf("INVALID OPTION--------\n");
		}
	}
}







//----------------------------------------------------------------

void display()
{
	struct node *temp;
	int count=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		count++;
		printf("priority value: %d ---- data: %d\n",temp->priority,temp->data);
		temp=temp->next;
	}

	printf("no. of nodes = %d\n",count);
}


//----------------------------------------------------------------------------

void insert(int num,int pr)
{
	struct node *ptr,*temp,*p;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{

		printf("FAILED TO ALLOCATE MEMORY\n");
		exit(1);
	}

	ptr->data=num;
	ptr->priority=pr;
	
	if(pr<0)
	{
		printf("priority cant be negative so enter a valid priority\n");
		return;
	}

	if(head==NULL)
	{
		head=ptr;
		head->prev=NULL;
	        ptr->next=NULL;
		return;
	}

	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority>pr)
			break;
		if(temp->next==NULL)
			break;
		temp=temp->next;
	}
	if(temp->priority>pr)
	{
		if(temp->prev==NULL)
		{
			temp->prev=ptr;      //-----------------if it is first node so we need to add before that node------------------------
			ptr->next=temp;
			head=ptr;
		}
		else
		{
			temp->prev->next=ptr;    //----------------------add in between nodes that is already we have first reference node we already addded a node first so the reference node is now                                                                    second  node so the next node is added in between these two nodes......................
			ptr->next=temp;
			ptr->prev=temp->prev;
			temp->prev=ptr;
		}
	}
	else if(temp->priority<=pr)
	{
		ptr->prev=temp;
		ptr->next=temp->next;
                temp->next=ptr;

	}

}

//-----------------------display------------------------------------

void display2(int pr)
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
		if(temp->priority==pr)
		{
			printf("[%d----%d]\n",temp->data,temp->priority);
		}
		temp=temp->next;
	}
}


//-----------------------------------------------------------------------------


void delete_ent()
{
	struct node *temp;
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

}



//------------------------------------------------------------------------------

void create_list(int *pptr,int *prp,int n)
{
	int i;
	struct node *ptr,*temp,*p;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{

			printf("FAILED TO ALLOCATE MEMORY\n");
			exit(1);
		}

		ptr->data=pptr[i];
		ptr->priority=prp[i];
		
		if(prp[i]<0)
		{
			printf("priority cant be negative so enter a valid priority\n");
			break;
		}

		if(head==NULL)
		{
			head=ptr;
			head->prev=NULL;
		        ptr->next=NULL;
			//return;
		}
		else
		{

			temp=head;
			while(temp!=NULL)
			{
				if(temp->priority>prp[i])
					break;
				if(temp->next==NULL)
					break;
				temp=temp->next;
			}
			if(temp->priority > prp[i])
			{
				if(temp->prev==NULL)
				{
					temp->prev=ptr;
					ptr->next=temp;
					head=ptr;
				}
				else
				{
					temp->prev->next=ptr;
					ptr->next=temp;
					ptr->prev=temp->prev;
					temp->prev=ptr;
				}
			}
			else if(temp->priority<=prp[i])
			{
				ptr->prev=temp;
				ptr->next=temp->next;
				//temp->next->prev=ptr;
				temp->next=ptr;
			}
		}
	}

}


//-----------------------------------------------------------------------------------------------

void delete_prii(int pr)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==pr)
		{
			if(temp==head)
			{
				temp->next->prev=temp->prev;
				head=temp->next;
			}
			else
				temp->prev->next=temp->next;	

			if(temp->next!=NULL)
				temp->next->prev=temp->prev;

			free(temp);
		//	return;
		}
		temp=temp->next;
	}
}

//------------------------------------------------------------------------------------------------



void delete_data_pri(int num,int  pr)
{
        struct node *temp;
        if(head==NULL)
        {
                printf("queue is empty\n");
                return;
        }
        temp=head;
        while(temp!=NULL)
        {
                if ((temp->priority==pr)&&(temp->data==num))
                {
                                                                     
			if(temp==head)                               // if the data and priority is found at first node so we want to delete that node [ no before node ]......
			{
                                temp->next->prev=temp->prev;
                                head=temp->next;
                        }
                        else                                         // if the node is not the first node [ middle node ]---------------------
 				temp->prev->next=temp->next;
                        
			
			if(temp->next!=NULL)                         // last node  [ no after node ]------------------
                                temp->next->prev=temp->prev;


                        free(temp);
                //      return;
                }
                temp=temp->next;
        }
}

//------------------------------------------------------------------------------

void delete_first_pri(int pr)
{
     struct node *temp;
        if(head==NULL)
        {
                printf("queue is empty\n");
                return;
        }
        temp=head;
        while(temp!=NULL)
        {
                if (temp->priority==pr)
                {
                        if(temp==head)
			{
                                temp->next->prev=temp->prev;
                                head=temp->next;
                        }
                        else
                                temp->prev->next=temp->next;
                        
			if(temp->next!=NULL)
                                temp->next->prev=temp->prev;


                        free(temp);
                      return;
                }
                temp=temp->next;
        }
}
//-----------------------------------------Create list------------------
/*void create_list(int *iptr,int *prior,int n)
{
	int i;
	struct node *ptr,*temp,*p;
	for(i=0;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{

			printf("FAILED TO ALLOCATE MEMORY\n");
			exit(1);
		}

		ptr->data=iptr[i];
		ptr->priority=prior[i];
		ptr->next=NULL;
		if(prior[i]<0)
		{
			printf("priority cant be negative so enter a valid priority\n");
			break;
		}

		if(head==NULL)
		{
			head=ptr;
			head->prev=NULL;

		}
		else
		{

			temp=head;
			while(temp!=NULL)
			{
				if(temp->priority>prior[i])
					break;
				if(temp->next==NULL)
					break;
				temp=temp->next;
			}
			if(temp->priority>prior[i])
			{
				if(temp->prev==NULL)
				{
					temp->prev=ptr;      //-----------------if it is first node so we need to add before that node------------------------
					ptr->next=temp;
					head=ptr;
				}
				else
				{
					temp->prev->next=ptr;    //----------------------add in between nodes that is already we have first reference node we already addded a node first so the reference node is now second  node so the next node is added in between these two nodes......................
					ptr->next=temp;
					ptr->prev=temp->prev;
					temp->prev=ptr;
				}
			}
			else if(temp->priority<=prior[i])
			{
				ptr->prev=temp;
				ptr->next=temp->next;
				temp->next=ptr;

			}
		}
	}
}*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------



void selectionsort_data()
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
			if(p->priority==q->priority)
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
}

//---------------------------------------------------------------------


void selectionsort_link()
{
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->priority==q->priority)
			{
				if((p->data) > (q->data))
				{
					if(p->next!=q)                               //----------[ "NON ADJACENT NODES" ]------------------
					{
						temp=p->prev;
						p->prev=q->prev;
						q->prev=temp;

						temp=p->next;
						p->next=q->next;
						q->next=temp;
						

						if(p!=head)                   //---------------[means]:--> "p node is not the first node"-----------
							q->prev->next=q;
						else
							head=q;
						
						if(p->next!=NULL)               //-----------[MEANS]:-->  "not the last node"-------------
							p->next->prev=p;


						q->next->prev=q;

						p->prev->next=p;
					}

					else                                  //-------------------[ "ADJACENT NODES" ]------------------------
					{
						p->next=q->next;
						q->next=p;
						q->prev=p->prev;
						p->prev=q;

						if(p!=head)                  //----------[MEANS]:--> "not the last node"..
							q->prev->next=q;
						else
							head=q;

						if(p->next!=NULL)              //---------------[ "not the last node" ]---------------------------------
							p->next->prev=p;
					}
					temp=p;
					p=q;
					q=temp;

				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------











