#include <stdio.h>
//借鉴了网上一堆代码 结果运行结果一个不对 实在不行干脆自己敲代码 结果终于对了
//思路：首先把范围20-0.01 变为2000到1 然后暴力枚举 
double change(double money )
{
	int i2000, i1000, i100, i10, i1;
	double mc = money * 100;
	double r=0;
	for (i2000 = 0; i2000 <= mc / 2000; i2000++)
	{
		r = mc - i2000 * 2000 ;
		if (r < 2000)
			break;
	}
	for (i1000 = 0; i1000 <= mc / 1000; i1000++)
	{
		r = mc - i2000 * 2000 - i1000 * 1000;
		if (r < 1000)
			break;
	}
	for (i100 = 0; i100 <= mc / 100; i100++)
	{
		r = mc - i2000 * 2000 - i1000 * 1000 - i100 * 100;
		if (r < 100)
			break;
	}
	for (i10 = 0; i10 <= mc / 10; i10++)
	{
		r = mc - i2000 * 2000 - i1000 * 1000 - i100 * 100 - i10 * 10;
		if (r < 10)
			break;
	}
	for (i1 = 0; i1<= mc / 1; i1++)
	{
		r = mc - i2000 * 2000 - i1000 * 1000 - i100 * 100 - i10 * 10 - i1 * 1;
		if (r < 0)
			break;
	}

			printf("20块钱%d张，10块钱%d张,1块钱%d张,1角钱%d张,1分钱%d张", i2000, i1000, i100, i10, i1);
			return 0;
}
int main()
{
	change(34.12);
	return 0;
}
