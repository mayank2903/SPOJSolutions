#include<stdio.h>
#define gtc getchar_unlocked()
typedef long long int ll;
inline ll read_int()
{
    register ll noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
inline ll abs(ll a)
{
	if(a<0)return -a;
	return a;
}
inline ll exp(ll a, ll pow, ll p)
{
	if(pow==0)return 1;
	if(pow==1)return a%p;
	ll ans=exp(a,pow/2,p);
	if(pow&1)
		return (((ans*ans)%p)*a)%p;
	else return (ans*ans)%p;
}
int main()
{
	int  t;
	ll n,p,fact,invfact,lim,i;
	scanf("%d",&t);
	//printf("2pow 3=%lld\n",exp(2,3,5));
	while(t--)
	{
		n=read_int();p=read_int();
		if(n>=p){printf("0\n");continue;}
		lim=p-n-1;fact=1;
		//printf("lim=%lld\n",lim);
		for(i=2;i<=lim;i++)
		{
			fact*=i;
			fact%=p;
		}
		//printf("fact=%lld\n",fact);
		invfact=exp(fact,p-2,p);//calculating fact^(p-2) by exponentiation
		//printf("invfact=%lld\n",invfact);
		//printf("prod=%lld\n",(fact*invfact)%p);
		if(abs(n-p)&1)
		{
			invfact=-invfact+p;
		}
		//printf("invfact=%lld\n",invfact);
		//printf("prod=%lld\n",(fact*invfact)%p);
		printf("%lld\n",invfact%p);
	}
	return 0;
}
