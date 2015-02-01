#include<stdio.h>
#include<math.h>
#define max(a,b) a>b?a:b
typedef long long int ll;
int primes[31622];
//sieve till 31622
void sieve()
{
	int i,j;
	for(i=2;i<31622;i++)
		primes[i]=1;
	primes[0]=primes[1]=0;
	for(i=2;i*i<=31621;i++)
	{
		if(primes[i])
		{
			//printf("Prime%lld\n",i);
			for(j=i*i;j<=31621;j+=i)
			{
				primes[j]=0;
			}
		}
	}
	//printf("count=%d\n",c);
}
int main()
{
	int t;
	ll a[100001];
	ll first_multiple,m,n,i,j,diff,q,sroot;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&m,&n);
		diff=n-m;sroot=sqrt(n);
		for(i=0;i<=diff;i++)a[i]=1;//assume all to be primes
		//cancelling all multiples of the primes i have:
		//if some part between m and n matches intervals of primes already existing..ill just copy them here:
		if(m==1)a[0]=0;
		for(i=2;i<=sroot;i++)
		{
			if(primes[i])
			{
				//finding first multiple of this prime:
				q=m/i;
				first_multiple=(m%i)?(q+1)*i:m;
		//		printf("First multiple of %lld=%lld\n",i,first_multiple);
				//cancelling all its multiples between m and n.
				for(j=first_multiple;j<=n;j+=i)
				{
					if(j!=i)
					a[j-m]=0;//marking them as not prime.
				}
			}
		}
		//printing all primes bw m,n:
		for(i=0;i<=diff;i++)
		{
				if(a[i])
					printf("%lld\n",i+m);
		}
	}
	return 0;
}
