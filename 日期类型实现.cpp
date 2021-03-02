//*������д��2020��11��  ��vs2019���������� 2021��� �����޸Ŀ���vc++������
//*�Ѿ�Ͷ����csdn https://blog.csdn.net/nruuu/article/details/111354222
#include <iostream>
#include <stdio.h>
#define Status int
#define OK 1
#define ERROR 0
using namespace std;

typedef struct date//�ṹ�����Ͷ���
{
	int year, month, day;
}Date;
Status  InitDate( Date &D)//�������ͳ�ʼ��
{

	int y, m, d;
	cout << "the year:";
	cin >> y;
	cout << "the month:";
	cin >> m;
	cout << "the day:";
	cin >> d;
	D.year = y;
	D.month = m;
	D.day = d;

	return OK;
}
Status printdate(Date D)//�����������
{
	
	cout << D.year << "��";
	cout << D.month << "��";
	cout << D.day << "��"<<endl;
	return OK;
}
Status IsLeapYear(Date D)//�ж��Ƿ�Ϊ����
{
	if (((D.year % 4 == 0) && (D.year % 100 != 0) )|| (D.year % 400 == 0))
		return OK;
	else
		return ERROR;
}
Status IsYear(Date D)//�ж������
{
	if (D.year <= 0 || D.month > 12 || D.month <= 0 || D.day <= 0 || D.day > 31)
		return ERROR;
	else
	{
		if (IsLeapYear(D))
		{
			if (D.month == 2 && (D.day == 28 || D.day == 30 || D.day == 31))
				return ERROR;
			else
				return OK;
		}
		else
		{
			if ((D.month == 4 || D.month == 6 || D.month == 9 || D.month == 11) && (D.day == 31))
				return ERROR;
			if (D.month == 2 && (D.day == 29 || D.day == 30 || D.day == 31))
				return	ERROR;
			else
				return OK;
		}
	}
}
int FebDay(int year)//�ж���һ��2�·ݵ�����
{
	int febday;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return febday = 29;
	else
		return febday = 28;
		
}
int yearday(int year)//�ж��������
{
	int yday;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		yday = 366;
	else
		yday = 365;
	return yday;
}
int DayofYear(Date D)//����������һ������һ��ĵڼ���
{
		int i, total = 0;
		int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		months[2] = FebDay(D.year);
		for (i = 1; i < D.month; i++)
			total = total + months[i];
		total = total + D.day;
		return total;
}

int cmpdate(Date d, Date s)//��������֮������
{
	int result;
	if (d.year == s.year)
	{
		if (d.month == s.month)
		{
			if (d.day == s.day)
				result = 0;
			else result = d.day - s.day;
		}
		else result = d.month - s.month;
	}
	else result = d.year - s.year;
	return result;
}
int InterDay(Date d, Date s)
{
	int result, te, ts, total;
	int year, start, end, day;
	int i;
	result = cmpdate(d, s);
	if (result > 0)
	{
		start = s.year;
		end = d.year;
		te = DayofYear(d);
		ts = DayofYear(s);
	}
	else if (result < 0)
	{
		start = d.year;
		end = s.year;
		ts = DayofYear(d);
		te = DayofYear(s);
	}
	else return 0;
	if (start == end)
		return abs(te - ts);
	else
	{
		total = 0;
		for (i = start; i <= end; i++)
		{
			day = yearday(i);
			if (i == start)
				total = total + day - ts;
			else if (i == end)
				total = total + te;
			else
				total = total + day;
		}
	}
	return total;
}
Status WeekofDay(Date D)//���չ�ʽ�ж��������������ڼ�
{
	int yearc, yearr,w;
	if (D.month == 1 || D.month == 2)
	{
		D.month = D.month + 12;
		D.year = D.year - 1;
	}
	yearc = D.year / 100;
	yearr = D.year % 100;
	w = (yearr + yearr / 4 + yearc / 4 - 2 * yearc + 13 * (D.month + 1) / 5 + D.day - 1) % 7;
	if(w<0)
		w=w+7;
	switch (w)
	{
	case 0:
		cout << "Sunday";
		break;
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	}
	return OK;
}
Status datestoday(Date D, int n, Date& S)//���N��������Ϊ
{
	int i;
	int d = D.day;
	int m = D.month;
	int y= D.year;
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	months[2] = FebDay(D.year);
	for (i = 0; i < n; i++)
	{
		d++;
		if (d > months[m])
		{
			m++;
			d = 1;
		}
		if (m > 12)
		{
			y++;
			m = 1;
		}
	}
		S.year = y;
		S.month = m;
		S.day = d;
		printdate(S);
		return OK;
}




int main()
{
	Date D;
	Date S;
	int totalday;
	int interday;
	InitDate(D);
	InitDate(S);
	if (IsYear(D))
	{
		cout << "true" << endl;
		printdate(D);
	}
	else
		cout << "false" << endl;
	if (IsYear(S))
	{
		cout << "true" << endl;
		printdate(S);
	}
	else
		cout << "false" << endl;
	if (IsYear(D))
	{
		totalday = DayofYear(D);
		cout << "����Ϊ:" << totalday << endl;
	}
	else
		return ERROR;
	if (IsYear(D) && IsYear(S))
	{
		cout << "����Ϊ";
		WeekofDay(D);
		cout << endl;
		cout << "����Ϊ";
		WeekofDay(S);
		cout << endl;
		interday = InterDay(D, S);
		cout << "�����ڼ������Ϊ:" << interday << endl;
		cout << "���" << 117 << "�����������Ϊ:";
		datestoday(D, 117, S);
	}
	else
		return ERROR;


}










/*���Խ��
the year:1995
the month:11
the day:7
the year:2001
the month:8
the day:16
true
1995��11��7��
true
2001��8��16��
����Ϊ��311
����ΪTuesday
����ΪThursday
�����ڼ������Ϊ��2109
���117�����������Ϊ��1996��3��4��


the year:1997
the month:2
the day:29
the year:2001
the month:6
the day:15
false
true
2001��6��15��
*/