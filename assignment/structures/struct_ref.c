
//.........call by value mechanism in structures................

#include<stdio.h>
struct book
{
	char name[32];
	int nop;
	float price;
};

/*void main()
{
	struct book b={"c",500,350};
	display(b);
}

void display(struct book b)
{
	printf("%s\n",b.name);
	printf("%d\n",b.nop);
	printf("%f\n",b.price);
}*/


//.................call by reference mechanism in structures..........



void main()
{
	struct book akku={"akku",699,400};
	display(&akku);
}
  

void display(struct book *ptr)
{
	printf("address:%-14p----- name:%s\n",ptr->name,ptr->name);
	printf("address:%-14p----- nop:%d\n",ptr->nop,ptr->nop);
	printf("address:%-14p----- price:%f\n",ptr->price,ptr->price);
}


