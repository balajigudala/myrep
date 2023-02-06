#include<stdio.h>
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
	char gender;
	struct dob dt;
};



void main()
{
	struct employee e={"sheshu",4,400000,'m',18,5,1999};
	printf("name: %s\n",e.name);
	printf("id: %d\n",e.id);
	printf("salary: %f\n",e.salary);
	printf("gender: %c\n",e.gender);
	printf("date-month-year: %d-%d-%d\n",e.dt.date,e.dt.month,e.dt.year);
	
	
}



