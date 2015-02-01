#include<stdio.h>
int main()
{
    int t;
    long long int n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
	ans=n*(3*n+1)/2;
	ans%=1000007;
	printf("%lld\n",ans);
    }
    return 0;
}
