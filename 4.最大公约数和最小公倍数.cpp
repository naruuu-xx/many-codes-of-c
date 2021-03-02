#include <stdio.h>
#define Status int
#define OK 1
int mod;
int temp;
Status gcd(int a,int b)
{
	if(a==0&&b!=0)
		return b;
	if(b==0&&a!=0)
		return a;
	else if(a!=0&&b!=0)
	{
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
	}
	return OK;
}
Status lcm(int a,int b)
{
	if(a!=0&&b!=0)
	{
		int lcm=(a*b)/gcd(a,b);
		return lcm;
	}
	else
	{
		if(a==0)
			return b;
		if(b==0)
			return a;
	}
	return OK;

}
void main()
{
	printf("%d",gcd(12,10));
	printf("\n");
	printf("%d",lcm(12,10));
	printf("%\n");
	printf("%d",gcd(22,4));
	printf("\n");
	printf("%d",lcm(22,4));
	printf("%\n");
	printf("%d",gcd(96,49));
	printf("\n");
	printf("%d",lcm(96,49));
	printf("%\n");
	printf("%d",gcd(12,27));
	printf("\n");
	printf("%d",lcm(12,27));
	printf("\n");
	
}