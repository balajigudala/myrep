#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * link;
};
struct node*head=NULL;
 
void main()
{
	struct node *temp;
	int num,val;
	printf("enter the num and val\n");
	scanf("%d %d",&num,&val);

	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num);
		{
			struct node *ptr=(struct node*)malloc(1*sizeof(struct node ));
			ptr->data=val;
			ptr->link=temp->link;
			temp->link=ptr;
			return;
		}
		temp=temp->link;
	}
}


