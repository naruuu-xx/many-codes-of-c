#include <stdio.h>
#include<math.h>
double sum(double LP,double Mir,double RY)//LP本金 Mir月利率 RY还款年数
{
	double sum;
	sum=LP*(Mir*pow((1+Mir),(RY*12)))/(pow((1+Mir),(RY*12))-1);
	return sum;
}
int main()
{
	double num;
	num = sum(100000,0.005875,5);
	printf("每月还款额为:%f",num);
	return 0;
}