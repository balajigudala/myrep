void deleteduplicate_queue()
{
	struct *p,*q,*s;
	if(rear==NULL)
	{
		printf("queue is empty");
		return;
	}
	for(p=front;p!=NULL;p=p->link)
	{
		for(s=p,q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data==q->data)
			{
				s->link=q->data
					if(q==rear)
						rear=s;
				free(q);
			}
			q=s;
		}
	}
}

