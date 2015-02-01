#include<stdio.h>
#include<algorithm>
#include<utility>
#define mp make_pair
using namespace std;
int cost[101],fun[101];
pair<int, int> nsack(int n, int b)
{
	int mat[n+1][b+1],costs[n+1][b+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(i==0||j==0)
			{
				mat[i][j]=0;
				costs[i][j]=0;
			}
			
			else
			{
				if(cost[i]>j)
				{
					mat[i][j]=mat[i-1][j];
					costs[i][j]=costs[i-1][j];
				}
				
				else
				{
					int x=mat[i-1][j-cost[i]]+fun[i];
					int y=mat[i-1][j];
					
					if(x>=y)
					{
						mat[i][j]=x;
						
						if(x==y)
						costs[i][j]=min(cost[i]+costs[i-1][j-cost[i]],costs[i-1][j]);
						
						else costs[i][j]=cost[i]+costs[i-1][j-cost[i]];
					}
					
					else
					{
						mat[i][j]=y;
						costs[i][j]=costs[i-1][j];
					}
				}
			}
		}
	}
	
	return mp(costs[n][b],mat[n][b]);
}
int main()
{
	int b,p,i;
	
	scanf("%d %d",&b, &p);
	
	while(b!=0 || p!=0)
	{
		for(i=1;i<=p;i++)
		{
			scanf("%d %d",&cost[i], &fun[i]);
		}
	
		pair<int, int> a=nsack(p,b);
		printf("%d %d\n",a.first, a.second);
		
		scanf("%d %d",&b, &p);
	}
	
	
	
}
