#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
struct student
{
	char name[32];
	unsigned int id_no;
	char gender;
	char grade;
};
void main()
{
	struct student s;


	printf("%ld\n",sizeof(s));
	printf("%ld\n",sizeof(struct student));
	printf("%p\n",&s);
        
	printf("..................................xox...............................\n");
        
	strcpy(s.name,"sheshureddy");
	printf("idno : ");
	scanf("%d",&s.id_no);
	printf("gender : ");
	__fpurge(stdin);
	scanf("%c",&s.gender);
	printf("grade : ");
	__fpurge(stdin);
	scanf("%c",&s.grade);


	
	printf("%s\n",s.name);
	printf("%d\n",s.id_no);
	printf("%c\n",s.gender);
	printf("%c\n",s.grade);

}

