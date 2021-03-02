/*
       复数类型实现_测试
	   编写时间：2020年9月20日
       编写人：薛彤彤
	   参考出处：教师课堂代码修改
*/
#include <stdio.h>
typedef struct complex
{
	float Realpart;
	float Imagepart;
}Complex;
void Create(Complex &c,float x,float y)
{
	c.Realpart=x;
	c.Imagepart=y;
}
float GetReal(Complex c)
{
	return c.Realpart;
}
float GetImage(Complex c)
{
	return c.Imagepart;
}
Complex Add(Complex c1,Complex c2)
{
	Complex sum;
	sum.Realpart=c1.Realpart+c2.Realpart;
	sum.Imagepart=c1.Imagepart+c2.Imagepart;
	return sum;
}
Complex Sub(Complex c1,Complex c2)
{
	Complex dif;
	dif.Realpart=c1.Realpart-c2.Realpart;
	dif.Imagepart=c1.Imagepart-c2.Imagepart;
	return dif;
}
Complex Mul(Complex c1,Complex c2)
{
	Complex cheng;
	cheng.Realpart=c1.Realpart*c2.Realpart-c1.Imagepart*c2.Imagepart;
	cheng.Imagepart=c1.Realpart*c2.Imagepart+c1.Imagepart*c2.Realpart;
	return cheng;
}
Complex Div(Complex c1,Complex c2)
{
	Complex chu;
	chu.Realpart=(c1.Realpart*c2.Realpart+c1.Imagepart*c2.Imagepart)/(c2.Realpart*c2.Realpart+c2.Imagepart*c2.Imagepart);
	chu.Imagepart=(c1.Imagepart*c2.Realpart-c1.Realpart*c2.Imagepart)/(c2.Realpart*c2.Realpart+c2.Imagepart*c2.Imagepart);
	if((c2.Realpart*c2.Realpart+c2.Imagepart*c2.Imagepart)==0)
		printf("the num doesnt exist");
	else
	return chu;
}
void Show(Complex c)
{
	if(c.Realpart!=0&&c.Imagepart!=0)
	printf("%.2f+%.2fi",c.Realpart,c.Imagepart);
	else if(c.Realpart!=0&&c.Imagepart==0)
	printf("%.2f",c.Realpart);
	else if(c.Realpart==0&&c.Imagepart!=0)
	printf("%.2fi",c.Imagepart);
	else if(c.Realpart==0&&c.Imagepart==0)
	printf("%d",0);
} 
static void helpTestShow(Complex C1,Complex C2)
{
	Show(C1);printf("\n");Show(C2);printf("\n");
	printf("he:");Show(Add(C1,C2));printf("\n");
	printf("cha:");Show(Sub(C1,C2));printf("\n");
	printf("ji:");Show(Mul(C1,C2));printf("\n");
	printf("shang:");Show(Div(C1,C2));printf("\n\n");
}
void TestComplex()
{
	Complex C1,C2;
	Create(C1,520,0);Create(C2,1314,0);helpTestShow(C1,C2);
	Create(C1,0.5,0.7);Create(C2,0.5,-0.7);helpTestShow(C1,C2);
	Create(C1,-8,0);Create(C2,0,10);helpTestShow(C1,C2);
	Create(C1,0,0);Create(C2,0,-90);helpTestShow(C1,C2);
	Create(C1,2,3);Create(C2,4,-9);helpTestShow(C1,C2);

}
main()
{
	TestComplex();
}