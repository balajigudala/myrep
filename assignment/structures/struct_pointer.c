

#include<stdio.h>
struct student
{
	char name[32];
	int id;                         // structure definatiion...............
	char gender;
	char grade;
};
void main()
{
	struct student s={"sheshu",1,'m','a'};
	struct student *ptr;        //   creating structure pointer of same type.........
	ptr=&s;                     //   assigning structure variable bas address of same type.........
 

//.... accessing structure members by using structure pointer with the help of arrow operator.....

	printf("%p-%s-size:%d\n",ptr->name,ptr->name,sizeof(ptr->name));
	printf("%p-%d-size:%d\n",&ptr->id,ptr->id,sizeof(ptr->id));
	printf("%p-%c-size:%d\n",&ptr->gender,ptr->gender,sizeof(ptr->gender));
	printf("%p-%c-size:%d\n",&ptr->grade,ptr->grade,sizeof(ptr->grade));
}

