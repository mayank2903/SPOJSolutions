#include<stdio.h>
#define m 1000000007
typedef long long int ll;
ll f[2][2]={{1,1},{1,0}};
ll x,y,z,w,ans;
inline ll fastmul(ll a, ll b)
{
	ll ans=0;
	while(b)
	{
		if(b&1){ans=(ans+a)%m;}
		a=(a<<1)%m;
		b=(b>>1)%m;
	}
	return ans%m;
}
void mul(int pow)
{
	if(pow==1)
		return;
	if(pow==2)
	{
		x=((fastmul(f[0][0],f[0][0]))%m+(fastmul(f[0][1],f[1][0]))%m)%m;
		y=((fastmul(f[0][0],f[0][1]))%m+(fastmul(f[0][1],f[1][1]))%m)%m;
		z=((fastmul(f[1][0],f[0][0]))%m+(fastmul(f[1][1],f[1][0]))%m)%m;
		w=((fastmul(f[1][0],f[0][1]))%m+(fastmul(f[1][1],f[1][1]))%m)%m;
		f[0][0]=x;
		f[0][1]=y;
		f[1][0]=z;
		f[1][1]=w;
		return;
	}
	mul(pow/2);
		x=((fastmul(f[0][0],f[0][0]))%m+(fastmul(f[0][1],f[1][0]))%m)%m;
		y=((fastmul(f[0][0],f[0][1]))%m+(fastmul(f[0][1],f[1][1]))%m)%m;
		z=((fastmul(f[1][0],f[0][0]))%m+(fastmul(f[1][1],f[1][0]))%m)%m;
		w=((fastmul(f[1][0],f[0][1]))%m+(fastmul(f[1][1],f[1][1]))%m)%m;
	f[0][0]=x;
	f[0][1]=y;
	f[1][0]=z;
	f[1][1]=w;
	if(pow&1)
	{
		x=(f[0][0]+f[0][1])%m;
		y=f[0][0];
		z=(f[1][0]+f[1][1])%m;
		w=f[1][0];
		f[0][0]=x;
		f[0][1]=y;
		f[1][0]=z;
		f[1][1]=w;
	}
}
int main()
{
	ll a,b;
	ll t,n,mm;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&mm);
		f[0][0]=1;
		f[0][1]=1;
		f[1][0]=1;
		f[1][1]=0;
		mul(mm+2);
		a=f[0][1];
		f[0][0]=1;
		f[0][1]=1;
		f[1][0]=1;
		f[1][1]=0;
		mul(n+1);
		b=f[0][1];
		ans=(a-b);
		if(ans<0)ans+=m;
		printf("%lld\n",ans%m);
	}
	return 0;
}
