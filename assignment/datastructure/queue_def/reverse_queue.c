void reverse_queue()
{
	struct node*prev,*cur,*next;
	if(rear==NULL)
	{
		printf("queue is empty");
		return;
	}
	prev=NULL;
	cur=front;
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	rear=front;
	front=prev;
}
