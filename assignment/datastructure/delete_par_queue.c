void deletepar_queue(inr num)
{
	struct *temp,*prev,*cur;
	if(front==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	if(front->data==num)
	{
		if(front->link==NULL)
		{
			free(front);
			front=rear=NULL;
			return;
		}
		temp=front;
		front=front->link;
		free(temp);
		return;
	}
	cur=front->link;
	prev=front;
	while(cur!=NULL)
	{
		if(cur!->data==num)
		{
			prev->link=cur->link;
			if(cur==rear)
			{
				rear=prev;
			}
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->link;
	}
	printf("element not found\n");
}


