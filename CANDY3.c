#include<stdio.h>
int main()
{
	long long int t,sum,x,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			sum+=x;if(sum>n)sum=sum%n;
		}
		if(sum%n==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
