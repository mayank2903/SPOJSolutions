#include<stdio.h>
#include<climits>
int main()
{
	long long int sum,mini,x,t,n,tt;
	
	scanf("%lld",&t);
	tt=t;
	
	while(t--)
	{
		mini=LONG_LONG_MAX;sum=0;
		scanf("%lld",&n);
		
		while(n--)
		{
			scanf("%lld",&x);
			sum+=x;
			
			if(sum<mini)mini=sum;
		}
		
		if(mini>0)
		{
			printf("Scenario #%lld: %lld\n",tt-t,1);
		}
		
		else printf("Scenario #%lld: %lld\n",tt-t,-mini+1);
	}
	
	return 0;
}
