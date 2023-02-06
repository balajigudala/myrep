#include<stdio.h>
main()
{
	int switch=0;
	int bulb=0xff;
	switch= switch & bulb;
	printf("%d\n",switch);
	switch= switch | bulb;
	printf("%d\n",bulb);
}
