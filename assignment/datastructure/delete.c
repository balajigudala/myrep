void idelete()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	else if(front->link==NULL)
	{
		free(front);
		front=rear=NULL;
		return;
	}
	else
	{
		temp=front;
		front=front->link;
		free(temp);
	}
}

