#include<stdio.h>
#include<stdbool.h>
#include<math.h>
typedef long long int ll;
ll totient[1000001];
ll val[1000001];
void sieve()
{
	int i,j;
	ll x;
	for(i=0;i<=1000000;i++)totient[i]=i;
	for(i=2;i<=1000000;i++)
	{
		if(totient[i]==i)
		{
			for(j=2*i;j<=1000000;j+=i)
			{
				totient[j]-=totient[j]/i;
			}
		}
	}
	for(i=2;i<=1000000;i++)
	{
		if(totient[i]==i)totient[i]-=1;
	}
	for(i=1;i<=1000000;i++)
	{
		x=i*totient[i];
		for(j=i;j<=1000000;j+=i)
		{
			val[j]+=x;
		}
	}
}
int main()
{
	int t,n,i,sroot;
	ll q;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		q=(1+val[n])*n/2;
		printf("%lld\n",q);
	}
	return 0;
}
