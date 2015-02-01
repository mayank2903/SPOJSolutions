#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
	if(b>a) return gcd(b,a);
	if(b==0)return a;
	if(b==1)return 1;
	return gcd(b,a%b);
}
int main()
{
	int t;
	long long int a,b,xVal,yVal,gcdAB,lcmAB;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		gcdAB=gcd(a,b);
		lcmAB=a*b/gcdAB;
		xVal=lcmAB/a;
		yVal=lcmAB/b;
		printf("%lld %lld\n",xVal,yVal);
	}
	return 0;
}
