#include <stdio.h>
void input(int a[],int n)
{
	for(int i=1;i<n+1;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",a+i);
	}
}
void change(int a[],int n,int m)
{
	for(int i=1;i<n;i++)
	{
		int temp;
		temp=a[i];
		a[i]=a[i+1];
		a[i+1]=temp;
	}
}
void output(int a[],int n)
{
	for(int i=1;i<n+1;i++)
		printf("%d,",*(a+i));
	printf("\n");
}
int main()
{
	int a[255];
	input(a,6);
	output(a,6);
	for(int i=1;i<6;i++)
	{
		change(a,6,1);
		output(a,6);
	}
	return 0;
}