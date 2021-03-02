
//编写日期： 2020年12月8日
//运行情况：vs2019，vc++ 完美运行
/*内容涵盖：
1.初始化
2.分数的显示
3.分数化简
4.加减乘除实现
利用最大公约数和最小公倍数

*/
#include <stdio.h>
//#include <bits/stdc++.h> vs2019下运行请取消这一行的注释
#include <iostream>
#define OK 1
#define ERROR 0
#define Status int
using namespace std;

typedef struct  Fraction//分数结构体定义
{
	int numerator;
	int denominator;
}fraction;
Status InitFrac(fraction& F)//结构体初始化
{
	int numer;
	int denom;
	
	cout << "分子为：";
	cin >> numer;
	cout << "分母为：";
	cin >> denom;
	F.denominator = denom;
	F.numerator = numer;
	return OK;
}

int gcd(fraction F)//最大公约数
{
	int r;
	int tmp;
	int a, b;
	a = F.numerator;
	b = F.denominator;
	if (b == 0)
		return ERROR;
	else
	{
		if (b < a )
		{
			tmp = b;
			b = a;
			a = tmp;
		}
		while (b != 0&&a!=0)
		{
			r = b % a;
			b = a;
			a = r;
		}
		return b;
	}
}
Status IsFraction(fraction F)//判断是否为分数
{
	if (F.denominator != 0)
		return OK;
	else
		return ERROR;
}
void SimpFraction(fraction F)//分数的化简
{
	if (IsFraction(F))
		cout << "最简形式为：" << F.numerator / gcd(F) << "/" << F.denominator / gcd(F) << endl;
	else
		cout << "分数不存在"<<endl;
}
int lcm(fraction F,fraction G)//两个分数最小公倍数的求解
{
	int Lcm = 0;
	int tmp=0;
	int a, b;
	a = F.denominator;
	b = G.denominator;
	if (b == 0)
		Lcm = a;
	else if (a == 0)
		Lcm = b;
	else if (a == 0 && b == 0)
		return ERROR;
	else
		Lcm = a * b;
	return Lcm;
}
Status printFrac(fraction F)//分数的表示
{
	if (IsFraction(F))
	{
		if (F.denominator != 0 && F.numerator != 0)
			cout << F.numerator << "/" << F.denominator << endl;
		else if (F.numerator == 0 && F.denominator != 0)
			cout << "0" << endl;
		return OK;
	}
	else
	{
		cout << "分数不存在" << endl;
		return 0;
	}


}

Status AddFraction(fraction F, fraction G, fraction& S)//分数加法
{
	if (IsFraction(F)||IsFraction(G))
	{
		int Snumerator;
		int Sdenominator;
		int Lcm;
		Lcm = lcm(F, G);
		if ((F.denominator == G.denominator))
		{
			Sdenominator = G.denominator;
			Snumerator = F.numerator + G.numerator;
		}
		else if (Lcm == F.denominator || Lcm == G.denominator)
		{
			Sdenominator = Lcm;
			if (F.denominator < G.denominator)
				Snumerator = (F.denominator * F.numerator) + G.numerator;
			if (G.denominator < F.denominator)
				Snumerator = (G.numerator * G.denominator) + F.numerator;
		}
		else
		{
			Sdenominator = Lcm;
			Snumerator = F.numerator * (Lcm / F.denominator) + G.numerator * (Lcm / G.denominator);
		}
		S.denominator = Sdenominator;
		S.numerator = Snumerator;
		cout << "分数相加后结果的";
		SimpFraction(S);
		return OK;
	}
	else
		cout << "分数不存在" << endl;
		return ERROR;


}
Status SubFraction(fraction F, fraction G, fraction& S)//分数减法
{
	if (IsFraction(F)||IsFraction(G))
	{
		int Snumerator;
		int Sdenominator;
		int Lcm;
		int a = F.numerator;
		int b = F.denominator;
		int c = G.numerator;
		int d = G.denominator;
		Lcm = lcm(F, G);
		if ((b == d))
		{
			Sdenominator = d;
			Snumerator = a - c;
		}
		else if (Lcm == b || Lcm == d)
		{
			Sdenominator = Lcm;
			if (b < d)
				Snumerator = (a * b) - c;
			if (d < b)
				Snumerator = (c * d) - a;
		}
		else
		{
			Sdenominator = Lcm;
			Snumerator = a * (Lcm / b) - c * (Lcm / d);
		}
		S.denominator = Sdenominator;
		S.numerator = Snumerator;
		cout << "分数相减之后结果的";
		SimpFraction(S);
		return OK;
	}
	else
		cout << "分数不存在" << endl;
		return ERROR;
}

Status MulFraction(fraction F, fraction G, fraction& S)//分数乘法
{
	if (IsFraction(F)||IsFraction(G))
	{
		int a = F.numerator;
		int b = F.denominator;
		int c = G.numerator;
		int d = G.denominator;
		int Snumerator;
		int Sdenominator;
		Sdenominator = b * d;
		Snumerator = a * c;
		S.denominator = Sdenominator;
		S.numerator = Snumerator;
		if (Sdenominator == 0)
			cout << "分数不存在" << endl;
		else if (Snumerator == 0)
			cout << "分数相乘结果为0" << endl;
		else
		{
			cout << "相乘结果的";
			SimpFraction(S);
		}
		return OK;
	}
	else
		return ERROR;
}
Status DivFraction(fraction F, fraction G, fraction& S)//分数除法
{
	if (IsFraction(F)||IsFraction(G))
	{
		int a = F.numerator;
		int b = F.denominator;
		int c = G.numerator;
		int d = G.denominator;
		int Snumerator;
		int Sdenominator;
		Sdenominator = b * c;
		Snumerator = a * d;
		S.denominator = Sdenominator;
		S.numerator = Snumerator;
		if (Sdenominator == 0)
			cout << "分数不存在" << endl;

		else if (Snumerator == 0)
			cout << "分数为0" << endl;
		else
		{
			cout << "分数相除结果的";
			SimpFraction(S);
		}
		return OK;
	}
	else
		return ERROR;
}



int  main()
{
	fraction F;
	fraction G;
	fraction S;
	InitFrac(F);
	printFrac(F);
	InitFrac(G);
	printFrac(G);
	SimpFraction(F);
	SimpFraction(G);
	AddFraction(F, G, S);
	SubFraction(F, G, S);
	MulFraction(F, G, S);
	DivFraction(F, G, S);
	return 0;
}

/*
测试结果
**输入：**
0
0
0
0
**输出：**
分子为：0
分母为：0
分数不存在
分子为：0
分母为：0
分数不存在
分数不存在
分数不存在
分数不存在
分数不存在

**输入：**
114
114514
514
114514
**输出：**
分子为：114
分母为：114514
114/114514
分子为：514
分母为：114514
514/114514
最简形式为：57/57257
最简形式为：257/57257
分数相加后结果的最简形式为：314/57257
分数相减之后结果的最简形式为：200/-57257
相乘结果的最简形式为：14649/57138577
分数相除结果的最简形式为：57/257

**输入：**
615
1722
1107
1923
**输出：**
分子为：615
分母为：1722
615/1722
分子为：1107
分母为：1923
1107/1923
最简形式为：5/14
最简形式为：369/641
分数相加后结果的最简形式为：8371/8974
分数相减之后结果的最简形式为：1961/-8974
相乘结果的最简形式为：1845/8974
分数相除结果的最简形式为：3205/5166

**输入：**
1
0
2
7
**输出：**
分子为：1
分母为：0
分数不存在
分子为：2
分母为：7
2/7
分数不存在
最简形式为：2/7
分数相加后结果的最简形式为：2/7
分数相减之后结果的最简形式为：-2/7
分数不存在
分数不存在

**输入：**
0
22
78
45
**输出：**
分子为：0
分母为：22
0
分子为：78
分母为：45
78/45
最简形式为：0/1
最简形式为：26/15
分数相加后结果的最简形式为：26/15
分数相减之后结果的最简形式为：-26/15
分数相乘结果为0
分数为0
*/
