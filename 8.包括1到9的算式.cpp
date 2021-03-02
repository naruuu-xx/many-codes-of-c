#include<stdio.h>
#define ok 1
#define error 0
int a[9];
int judge(int t,int *z,int bit)
{
	int *p1,*p2;
	for(p1=z;p1<z+bit;p1++)
	{
		*p1=t%10;
		if(*p1==0)
			return error;
		t=t/10;
		for(p2=a;p2<p1;p2++)
		{
			if(*p2==*p1)
				return error;
		}
	}
	return ok;
}
int main()
{
	int count=0;
	for(int m=123;m<=987;m++)
	{
		for(int n=m+1;n<=987;n++)
		{
			if(m+n>999)
				break;
			else
				if(judge(m,a,3)&&judge(n,a+3,3)&&judge(m+n,a+6,3))
					printf("%d. %d+%d=%d\n",++count,m,n,m+n);
		}
	}
	printf("共有%d种组合",count);
	return 0;
}