//�ݹ�����
//ԭ��ɾ����ź���˵ı��ȫ����ԭ���Ļ�������ǰ����ȥ������λ
//���Ƽ���f��n,m��=(f(n-1,m)+3)%n
#include <stdio.h>
int cir(int n,int m)
{
	int win=0;
	for(int i=2;i<=n;i++)
	{
		win=(win+m)%i;
	}
	return win+1;
}
int main()
{
	int winner=0;
	winner=cir(11,3);
	printf("%d\n",winner);
	return 0;
}