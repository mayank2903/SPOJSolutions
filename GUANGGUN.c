#include<stdio.h>
int main()
{
	long long int n,ans,m9;
	
	while(scanf("%lld",&n)!=EOF)
	{
		//find nearest multiple of 9<=n.
		m9=n-(n%9);
		ans=m9*9;
		m9=n-m9;
		ans+=m9*m9;
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
