void swap(int num,int val)
{
	int pos1=0,pos2=0;
	struct node*p,*q,*r,*s,*temp;
	if(num==val)
	
		return;
	if(front==NULL)
	{
		printf("queue is empty\n");
		return;
	}
	q=p=front;
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

		if(p!=front)
			r->link=q;
		else
			front=q;
		s->link=p;
		if(q==rear)
			rear=p;
	}
	else
	{
		p->link=q->link;
		q->link=p;
		if(p!=front)
			r->link=q;
		else
			front=q;
		if(q==rear)
			rear=p;
	}
}
	
