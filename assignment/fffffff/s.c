#include<stdio.h>
struct engine
{
	int hp;
	char enginetype;
	int cc;
	float milage;
	int rpm;
};

struct car
{
	char* colour;
	int price;
	//int cc;
	char* model;
	struct engine e;

};
 
void main()
{
//	struct car swift={"black",1200000,"axe",1200,'a',900,65,1828};
//	struct car polo={"blue",758585,"jhgfdk"};
	struct car benz={"green",1234567,"djkf",1200,'a',900,78,1200};
//	struct engine e={1200,'a',900,60,1200};

//printf("%s-%d-%d-%s\n",benz.colour,benz.price,benz.cc,benz.model);

printf("%s-%d-%s-%d-%c-%d-%f-%d\n",benz.colour,benz.price,benz.model,benz.e.hp,benz.e.enginetype,benz.e.cc,benz.e.milage,benz.e.rpm);
}




