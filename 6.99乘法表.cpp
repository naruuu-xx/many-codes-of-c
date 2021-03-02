#include <stdio.h>


int main()
{
	for(int i=1,j=1;i<10;i++)
	{
		printf("%d*%d=%d",i,j,i*j);
		printf("\t");
		for(int j=2;j<10;j++)
		{
			printf("%d*%d=%d",i,j,i*j);
			printf("\t");
		}
		printf("\n");

	}
	return 0;
}
