#include<stdio.h>
typedef long long int ll;
//storing primes till 10^6:
ll marked[1000001];
ll primes[78499];
ll count=0;
void sieve()
{
	int i,j;
	marked[1]=1;
	for(i=2;i<=1000;i++)
	{
		if(!marked[i])
		{
			primes[count++]=i;
			for(j=i*i;j<=1000000;j+=i)
			marked[j]=1;
		}
	}
	for(i=1001;i<=1000000;i++)
		if(!marked[i])primes[count++]=i;
/*
	printf("count=%d\n",count);
	printf("last prime=%d\n",primes[count-1]);
	*/
}
int maxdiv(ll n, ll divisor)
{
	int c=0;
	while(n%divisor==0)
	{
		n/=divisor;
		c++;
	}
	return c;
}
int ans(ll n)
{
	ll i;int f=0;
	//if prime and <=10^6
	if(n<=1000000 && !marked[n] && n%4==1)return 1;
	//if not prime:
	for(i=0;i<count;i++)
	{
		if(n%primes[i]==0){f=1;
		if(primes[i]%4==3 && maxdiv(n,primes[i])%2!=0)return 0;
		}
	}
	if(!f)//n is prime..
		return (n%4==1);
	return 1;
}
int main()
{
	int t;ll n;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(ans(n)==1)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
