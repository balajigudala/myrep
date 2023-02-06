#include<stdio.h>
void push(int *ptr,int l);
	void pop(int *ptr);
	void display(int *ptr);
	int  ascending(int *ptr,int n);
#define size 5
	int f=-1,r=-1;
	void main()
{
	int arr[size];
	int n;
	while(1)
	{
		printf("press\n1.push\n2.pop\n3.display\n4.ascending order\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:push(arr,size);
				break;
			case 2: pop(arr);
				break;
			case 3:
				display(arr);
				break;
			case 4:	ascending(arr,size);	
				break;

		}
	}
}




void push(int *ptr,int n)
{
	int num;
	if(f==-1)
		f++,r++;
	else if((r==size-1)&&(f==0)||(r==f-1))

	{
		printf("q is full\n");
		return;

	}
	else if(r==size-1)
	{
		r=0;
		printf("enter the valus\n");
		scanf("%d",&num);
		ptr[r]=num;
		return;
	}
	else 
	{
		r++;
	}
		printf("enter the value\n");
		scanf("%d",&num);
		ptr[r]=num;
	
}







void pop(int *ptr)
{
	if(f==-1)
	{
		printf("q is mt\n");
		return;
	}
	else if(f==r)
	{
		f=r=-1;
		return;
	}
	else if(f==size-1)
	{
		f=0;
		return;
	}
	f++;
}





void display(int *ptr)
{
	int i;
	if(f==-1)
	{
		printf("q is mt\n");
		return;
	}
	if(f<=r)


	{
		for(i=f;i<=r;i++)
			printf("%d\n",ptr[i]);
	}
	else if(r<f)
	{
		for(i=f;i<=size-1;i++)
			printf("%d\n",ptr[i]);
		for(i=0;i<=r;i++)
			printf("%d\n",ptr[i]);
	}
}




int ascending(int *ptr,int n)
{
	int i,j,temp;
	if(f==-1)
	{
		printf("q is mt\n");
		return -1;
	}
	if(f<=r)
	{
		for(i=f;i<=r;i++)
		{
			for(j=i+1;j<=r;j++)
			{
		          if(ptr[i]>ptr[j])
			  {
				  temp=ptr[j];
				  ptr[j]=ptr[i];
				  ptr[i]=temp;

			  }
			}
			printf("%d\n",ptr[i]);
		}
	}
	else if(r<f)
	{
		for(i=0;i<n;i++)
		{
			if((i<=r)||(i>=f))
			{
				for(j=i+1;j<n;j++)
				{
					if((i<=r)||(j>=f))
					{
						if(ptr[i]>ptr[j])
						{
							temp=ptr[i];
							ptr[i]=ptr[j];
							ptr[j]=temp;
						}
					}
				}
				printf("%d\n",ptr[i]);
			}
		}
	}
}
