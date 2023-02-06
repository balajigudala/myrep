
// call by reference......

#include<stdio.h>
#include<string.h>

struct book
{
	char name[32];
	int nop;
	float price;

};
void swap(struct book*,struct book *);
void display(struct book *,struct book *);

void main()
{
	struct book b1={"sheshu",300,363};
	struct book b2={"lord",500,963};
	swap(&b1,&b2);
	display(&b1,&b2);
}


void swap(struct book *b1,struct book *b2)
{
	struct book temp;
	strcpy(temp.name,b1->name);
	strcpy(b1->name,b2->name);
	strcpy(b2->name, temp.name);


	temp.nop=b1->nop;
	b1->nop=b2->nop;
	b2->nop=temp.nop;


	temp.price=b1->price;
	b1->price=b2->price;
	b2->price=temp.price;


}


void display(struct book*ptr,struct book*ptr1)
{
	printf("%p---------------%10s----------%s\n",ptr->name,ptr->name,ptr1->name);
	printf("%p---------------%10d----------%d\n",&ptr->nop,ptr->nop,ptr1->nop);
	printf("%p---------------%10f----------%f\n",&ptr->price,ptr->price,ptr1->price);
}

