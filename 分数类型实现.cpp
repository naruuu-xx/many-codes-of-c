//��д�ˣ�19��Ϣ������ѧ2�� Ѧͮͮ 
//��д���ڣ� 2020��12��8��
//���������vs2019��vc++ ��������
/*���ݺ��ǣ�
1.��ʼ��
2.��������ʾ
3.��������
4.�Ӽ��˳�ʵ��
�������Լ������С������
���ߣ�https://blog.csdn.net/nruuu/article/details/110881699
*/
#include <stdio.h>
//#include <bits/stdc++.h> vs2019��������ȡ����һ�е�ע��
#include <iostream>
#define OK 1
#define ERROR 0
#define Status int
using namespace std;

typedef struct  Fraction//�����ṹ�嶨��
{
	int numerator;
	int denominator;
}fraction;
Status InitFrac(fraction& F)//�ṹ���ʼ��
{
	int numer;
	int denom;
	
	cout << "����Ϊ��";
	cin >> numer;
	cout << "��ĸΪ��";
	cin >> denom;
	F.denominator = denom;
	F.numerator = numer;
	return OK;
}

int gcd(fraction F)//���Լ��
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
Status IsFraction(fraction F)//�ж��Ƿ�Ϊ����
{
	if (F.denominator != 0)
		return OK;
	else
		return ERROR;
}
void SimpFraction(fraction F)//�����Ļ���
{
	if (IsFraction(F))
		cout << "�����ʽΪ��" << F.numerator / gcd(F) << "/" << F.denominator / gcd(F) << endl;
	else
		cout << "����������"<<endl;
}
int lcm(fraction F,fraction G)//����������С�����������
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
Status printFrac(fraction F)//�����ı�ʾ
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
		cout << "����������" << endl;
		return 0;
	}


}

Status AddFraction(fraction F, fraction G, fraction& S)//�����ӷ�
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
		cout << "������Ӻ�����";
		SimpFraction(S);
		return OK;
	}
	else
		cout << "����������" << endl;
		return ERROR;


}
Status SubFraction(fraction F, fraction G, fraction& S)//��������
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
		cout << "�������֮������";
		SimpFraction(S);
		return OK;
	}
	else
		cout << "����������" << endl;
		return ERROR;
}

Status MulFraction(fraction F, fraction G, fraction& S)//�����˷�
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
			cout << "����������" << endl;
		else if (Snumerator == 0)
			cout << "������˽��Ϊ0" << endl;
		else
		{
			cout << "��˽����";
			SimpFraction(S);
		}
		return OK;
	}
	else
		return ERROR;
}
Status DivFraction(fraction F, fraction G, fraction& S)//��������
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
			cout << "����������" << endl;

		else if (Snumerator == 0)
			cout << "����Ϊ0" << endl;
		else
		{
			cout << "������������";
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
���Խ��
**���룺**
0
0
0
0
**�����**
����Ϊ��0
��ĸΪ��0
����������
����Ϊ��0
��ĸΪ��0
����������
����������
����������
����������
����������

**���룺**
114
114514
514
114514
**�����**
����Ϊ��114
��ĸΪ��114514
114/114514
����Ϊ��514
��ĸΪ��114514
514/114514
�����ʽΪ��57/57257
�����ʽΪ��257/57257
������Ӻ����������ʽΪ��314/57257
�������֮�����������ʽΪ��200/-57257
��˽���������ʽΪ��14649/57138577
�����������������ʽΪ��57/257

**���룺**
615
1722
1107
1923
**�����**
����Ϊ��615
��ĸΪ��1722
615/1722
����Ϊ��1107
��ĸΪ��1923
1107/1923
�����ʽΪ��5/14
�����ʽΪ��369/641
������Ӻ����������ʽΪ��8371/8974
�������֮�����������ʽΪ��1961/-8974
��˽���������ʽΪ��1845/8974
�����������������ʽΪ��3205/5166

**���룺**
1
0
2
7
**�����**
����Ϊ��1
��ĸΪ��0
����������
����Ϊ��2
��ĸΪ��7
2/7
����������
�����ʽΪ��2/7
������Ӻ����������ʽΪ��2/7
�������֮�����������ʽΪ��-2/7
����������
����������

**���룺**
0
22
78
45
**�����**
����Ϊ��0
��ĸΪ��22
0
����Ϊ��78
��ĸΪ��45
78/45
�����ʽΪ��0/1
�����ʽΪ��26/15
������Ӻ����������ʽΪ��26/15
�������֮�����������ʽΪ��-26/15
������˽��Ϊ0
����Ϊ0
*/