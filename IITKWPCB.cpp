#include<stdio.h>
typedef long long int ll;
ll gcd(ll a, ll b)
{
	return (b==0)?a:gcd(b,a%b);
}
int main()
{
	int t;
	ll i,n,start;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		start=n>>1;
		for(i=start;;i--)
		{
			if(gcd(n,i)==1)
			{
				printf("%lld\n",i);break;
			}
		}
	}
	return 0;
}
