#include<stdio.h>
#include<string.h>

struct dob
{
	int date;
	int month;
	int year;
};

struct employee
{
	char name[32];
	int id;
	float salary;
	struct dob *dt;
};


void main()
{
	struct employee e;
	struct dob dt={18,5,1999};
	strcpy(e.name,"sheshu");
	e.id=27;
	e.salary=400000;
	e.dt=&dt;
	printf("%s",e.name);
	printf("%d",e.id);
	printf("%f",e.salary);
	printf("%d-%d-%d\n",e.dt->date,e.dt->month,e.dt->year);


	 display(&e);
}

	void display(struct employee *ptr)
	{
		printf("%s",ptr->name);
		printf("%d",ptr->id);
		printf("%f",ptr->salary);
		printf("%d-%d-%d\n",ptr->dt->date,ptr->dt->month,ptr->dt->year);
	}

