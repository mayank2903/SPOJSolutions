#include<stdio.h>
int g[201][201];
int main()
{
	int t,n,i,j,k,dist;
	bool neigh;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
		}
		
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				dist=g[i][j];
				neigh=true;
				
				for(k=0;k<n;k++)
				{
					if(k==i ||k==j)continue;
					
					if(g[i][k]<dist && g[k][j]==(dist-g[i][k]))
					{
						neigh=false;
						break;
					}
				}
				
				if(neigh)
				printf("%d %d\n",i+1,j+1);
			}
		}
		
		puts("");
		
	}
	
	return 0;
}
