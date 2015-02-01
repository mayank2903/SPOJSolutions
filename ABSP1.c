#include<stdio.h>
typedef long long int ll;
int main()
{
	ll t,i,diff,n;
	ll x,subt,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
                sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
                        sum+=(2*i-1-n)*x;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
