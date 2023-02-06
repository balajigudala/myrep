void insert(int val)
{
	struct node *ptr=(struct node*)malloc(struct node);
	if(ptr==NULL)
	{
		printf("failed to allocate memory\n");
		exit(1);
	}
	ptr->data=val;
	ptr->link=NULL;
	if(rear==NULL)
	{
		front=rear=ptr;
		return;
	}
	rear->link=ptr;
	rear=ptr;
}



