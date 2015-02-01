#include<stdio.h>
int etfval[1000001];
void etf()
{
	int i,j;
	for(i=0;i<=1000000;i++)etfval[i]=i;
	for(i=2;i<=1000000;i++)
	{
		if(etfval[i]==i)
		{
			for(j=2*i;j<=1000000;j+=i)
			{
				etfval[j]-=etfval[j]/i;
			}
		}
	}
	for(i=2;i<=1000000;i++)if(etfval[i]==i)etfval[i]-=1;
}
int main()
{
	int t,n;
	etf();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",etfval[n]);
	}
	return 0;
}
