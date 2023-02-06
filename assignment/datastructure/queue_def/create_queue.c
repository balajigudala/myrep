
void create_queue(int *iptr,int n)
{
	int i;
	struct node*ptr;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		ptr->data=iptr[i];
		ptr->link=NULL;
		if(rear==NULL)
			rear=front=ptr;
		rear->link=ptr;
		rear=ptr;
	}
}
