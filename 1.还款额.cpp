#include <stdio.h>
#include<math.h>
double sum(double LP,double Mir,double RY)//LP���� Mir������ RY��������
{
	double sum;
	sum=LP*(Mir*pow((1+Mir),(RY*12)))/(pow((1+Mir),(RY*12))-1);
	return sum;
}
int main()
{
	double num;
	num = sum(100000,0.005875,5);
	printf("ÿ�»����Ϊ:%f",num);
	return 0;
}