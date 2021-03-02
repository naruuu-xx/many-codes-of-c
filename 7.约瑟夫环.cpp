//递归做法
//原理：删掉编号后的人的编号全都在原来的基础上提前（减去）了三位
//逆推即：f（n,m）=(f(n-1,m)+3)%n
#include <stdio.h>
int cir(int n,int m)
{
	int win=0;
	for(int i=2;i<=n;i++)
	{
		win=(win+m)%i;
	}
	return win+1;
}
int main()
{
	int winner=0;
	winner=cir(11,3);
	printf("%d\n",winner);
	return 0;
}