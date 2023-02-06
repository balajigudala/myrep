void delete_entire()
{
	struct node*temp;
	if(rear==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	while(front!=NULL)
	{
		temp=front;
		front=front->link;
		free(temp);
		rear=NULL;
	}
}

