#include <stdio.h>
#include <iostream>
#define Status int
#define OK 1
#define ERROR 0
typedef struct date//结构体类型定义
{
	int year, month, day;
}Date;
Status  InitDate( Date &D)//日期类型初始化
{

	int y, m, d;
	std::cout << "the year:";
	std::cin >> y;
	std::cout << "the month:";
	std::cin >> m;
	std::cout << "the day:";
	std::cin >> d;
	D.year = y;
	D.month = m;
	D.day = d;

	return OK;
}

Status WeekofDay(Date D)//判断日期这天是星期几
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
		std::cout << "Sunday";
		break;
	case 1:
		std::cout << "Monday";
		break;
	case 2:
		std::cout << "Tuesday";
		break;
	case 3:
		std::cout << "Wednesday";
		break;
	case 4:
		std::cout << "Thursday";
		break;
	case 5:
		std::cout << "Friday";
		break;
	case 6:
		std::cout << "Saturday";
		break;
	}
	return OK;
}
int main()
{
	Date D;
	InitDate(D);
	WeekofDay(D);
	return 0;
}