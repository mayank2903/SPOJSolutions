#include<stdio.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
ll knapsack[2001][2001];
ll wt[2001];
ll val[2001];
ll max(ll a, ll b)
{
if(a>b)return a;
else return b;
}
int main()
{
	ll i,j,n,W;
	scanf("%lld%lld",&W,&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&wt[i],&val[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				knapsack[i][j]=0;
			else if(wt[i-1]<=j)
				knapsack[i][j]=max(knapsack[i-1][j],knapsack[i-1][j-wt[i-1]]+val[i-1]);
			else
				knapsack[i][j]=knapsack[i-1][j];
		}
	}
	printf("%lld\n",knapsack[n][W]);
	return 0;
}
