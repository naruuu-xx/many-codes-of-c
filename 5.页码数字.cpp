#include <stdio.h>
int countDigit(int num,int target)
{
	int base=1;
	int sum=0;
	int n=num;
	while(n!=0)
	{
		sum+=base*(n/10);
		int cur=n%10;
		if(cur==target)
			sum+=num%base+1;
		else if(cur>target)
			sum+=1*base;
		base *=10;
		n=n/10;
	}
	printf("%d出现%d次\n",target,sum);
	return sum;
}
int countDigitzero(int num)
{
        int base = 1;
        int sum = 0;
        int n = num;

        while (n != 0) {
            sum += base * (n / 10 - 1);

            int cur = n % 10;
            if (cur == 0) {
                sum += num % base + 1;
            } else if (cur > 0) {
                sum += base;
            }

            base *= 10;
            n = n / 10;
        }
		printf("0出现%d次\n",sum);
        return sum;

}
int main()
{
	countDigitzero(24);
	countDigit(24,1);
	countDigit(24,2);
	countDigit(24,3);
	countDigit(24,4);
	countDigit(24,5);
	countDigit(24,6);
	countDigit(24,7);
	countDigit(24,8);
	countDigit(24,9);
	return 0;
}