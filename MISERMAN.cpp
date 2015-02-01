#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int cost[100][100];
int a[100][100];
int main()
{
	int t,n,m,i,j,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cost[i][j]=INT_MAX;
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<m;i++)
		{
			cost[0][i]=a[0][i];
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(j-1>=0)
				cost[i][j]=min(cost[i][j],a[i][j]+cost[i-1][j-1]);
				cost[i][j]=min(cost[i][j],a[i][j]+cost[i-1][j]);
				if(j+1<m)cost[i][j]=min(cost[i][j],a[i][j]+cost[i-1][j+1]);
			}
		}
		ans=INT_MAX;
		for(i=0;i<m;i++)
		{
			ans=min(ans,cost[n-1][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
