int reverse_num(int)
{
	int num, sum=0,temp,rem;
temp=num;
sum=0;
while(temp>0)
{
	rem=temp%10;
	temp=temp/10;
	sum=sum*10+rem;
}
return sum;
}

