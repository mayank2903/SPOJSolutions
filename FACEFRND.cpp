#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;
queue<int> qq;
int frnds[10000];
int marked[10000];
int main()
{
	int n,nbob,x,frnd,j,m,i;
	scanf("%d",&nbob);
	for(i=0;i<nbob;i++)
	{
		scanf("%d%d",&frnd,&m);
		frnds[frnd]=1;
		for(j=0;j<m;j++)
		{
			scanf("%d",&x);
			if(!marked[x]){marked[x]=1;qq.push(x);}
		}
	}
	int count=0;
	while(!qq.empty())
	{
		x=qq.front();
		qq.pop();
		if(frnds[x]==0)count++;
	}
	printf("%d\n",count);
	return 0;
}
