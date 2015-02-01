#include<stdio.h>
int main()
{
	long long int n,k,reqSum=0,sum=0,x,i;
	scanf("%lld%lld",&n,&k);
	reqSum=(n*(n-1))/2+n*k;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld",&x);
		sum+=x;
	}
	printf("%lld\n",reqSum-sum);
	return 0;
}
