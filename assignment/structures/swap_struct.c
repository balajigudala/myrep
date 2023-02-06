#include<stdio.h>
#include<string.h>
struct student
{
	// structure defination....
	
	char name[32];
	int id;
	char gender;
	char grade;
};

void main()
{
	// structure initialization.......
	
	struct student s1={"sheshu",1,'m','a'};
	struct student s2={"pavan",2,'m','a'};
	struct student temp;

	/*temp=s1;
	  s1=s2;                                            //...............FIRST METHOD FOR SWAPING.......................
	  s2=temp;*/

	strcpy(temp.name,s1.name);
	strcpy(s1.name,s2.name);
	strcpy(s2.name,temp.name);

	temp.id=s1.id;
	s1.id=s2.id;
	s2.id=temp.id;
	//...................ANOTHER METHOD FOR SWAPING....................
	temp.gender=s1.gender;
	s1.gender=s2.gender;
	s2.gender=temp.gender;                         //..............[[ we can use these methods for swaping,but according to its usage and according to problem]].............

	temp.grade=s1.grade;
	s1.grade=s2.grade;
	s2.grade=temp.grade;



	printf("%s\n",s1.name);
	printf("%d\n",s1.id);
	printf("%c\n",s1.gender);
	printf("%c\n",s1.grade);

	//............................................

	printf("%s\n",s2.name);
	printf("%d\n",s2.id);
	printf("%c\n",s2.gender);
	printf("%c\n",s2.grade);
}



