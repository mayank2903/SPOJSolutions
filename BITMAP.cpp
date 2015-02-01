#include<stdio.h>
#include<queue>
#include<utility>
#include<limits.h>
#include<ctype.h>
using namespace std;
int m,n;
int posx[4]={0,1,0,-1};
int posy[4]={1,0,-1,0};
int mindist[183][183];
queue<pair<int, int> > qq;
inline bool valid(int x, int y)
{
	return ((x>=0 && x<n)&&(y>=0 && y<m))?true:false;
}
void bfs()
{
	pair<int, int> out;
	int newx,newy,i;
	while(!qq.empty())
	{
		out=qq.front();
		qq.pop();
		for(i=0;i<4;i++)
		{
			newx=out.first+posx[i];
			newy=out.second+posy[i];
			if(valid(newx,newy))
			{
				if(mindist[out.first][out.second]+1<mindist[newx][newy])
				{
					mindist[newx][newy]=mindist[out.first][out.second]+1;
					qq.push(make_pair(newx,newy));
				}
			}
		}
	}
}
int main()
{
	int t,i,j,x;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<183;i++)
			for(j=0;j<183;j++)
				mindist[i][j]=INT_MAX;
		scanf("%d%d",&n,&m);
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				x=getchar()-48;
				if(x==1)
				{
					qq.push(make_pair(i,j));
					mindist[i][j]=0;
				}
			}
			getchar();
		}
		bfs();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%d ",mindist[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
