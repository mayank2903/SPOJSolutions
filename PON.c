#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int ll;
ll modexp(ll base, ll pow, ll mod)
{
	ll ans=1,a,b,tempans;
	if(pow==0)return 1;
	if(pow==1)return base%mod;
	while(pow)
	{
		if(pow&1)//ans=(ans*base)%mod;
		{
			//implementing ans=(ans*base)%mod
			a=ans;b=base;tempans=0;
			while(b)
			{
				if(b&1)tempans=(tempans+a)%mod;
				a=(a<<1)%mod;
				b>>=1;
			}ans=tempans;
		}
		//base=(base*base)%mod;
		//implementing base=(base*base)%mod;
		a=base;b=base;tempans=0;
		while(b)
		{
			if(b&1)tempans=(tempans+a)%mod;
			a=(a<<1)%mod;
			b>>=1;
		}base=tempans;
		pow>>=1;
	}
	return ans;
}
int main()
{
	int t,f;
	ll a,p,i;
	//printf("%llu\n",modexp(2,10,1024));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu",&p);
		if(p<=1){printf("NO\n");continue;}
		else if(p==2){printf("YES\n");continue;}
		else if(p%2==0){printf("NO\n");continue;}
		f=0;
		for(i=1;i<=2;i++)
		{
			//generate random 'a' <p
			a=rand()%(p-1)+1;
			//printf("Generated random:%llu\n",a);
			///check primality test
			if(modexp(a,p-1,p)!=1){f=1;break;}
		}
		if(f==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
