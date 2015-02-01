/*
 * shop.cpp
 *
 *  Created on: Dec 27, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
int pos[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
int r,c;
bool visited[50][50];
char str[50][50];
bool isvalid(int x, int y)
{
	return x>=0 && x<r && y>=0 && y<c;
}
int dijkstra(int x, int y, int xx, int yy)
{
	pair<int, pair<int, int> > top;
	priority_queue<pair<int, pair<int, int> > >qq;
	qq.push(make_pair(0,make_pair(x,y)));
	visited[x][y]=true;
	while(!qq.empty())
	{
		top = qq.top();
		qq.pop();
		int dist = top.first;
		int HX = top.second.first;
		int HY = top.second.second;
		//printf("popped=(%d,%d) with dist=%d\n",HX,HY,-dist);
		visited[HX][HY]=true;
		if(HX==xx && HY==yy)
			return dist;
		for(int i=0;i<4;i++)
		{
			int tx = HX+pos[i][0];
			int ty = HY+pos[i][1];
			if(isvalid(tx,ty) && !visited[tx][ty] && str[tx][ty]!='X')
			{
				if(tx==xx && ty==yy)return dist;
				pair<int, int> coord = make_pair(tx,ty);
				qq.push(make_pair(dist-str[tx][ty]+'0', coord));
			}
		}
	}
}
int main()
{
	int x,xx,y,yy;
	while(true)
	{
		cin>>c>>r;
		memset(visited, false, sizeof visited);
		if(c+r==0)
			return 0;
		x=-1;xx=-1;
		for(int i=0;i<r;i++)
		{
			scanf("%s",str[i]);
			if(x!=-1 && xx!=-1)
				continue;
			for(int j=0;j<c;j++)
			{
				if(str[i][j]=='S')
				{
					x=i;y=j;
				}
				else if(str[i][j]=='D')
				{
					xx=i;yy=j;
				}
			}
		}
		//cout<<x<<y<<" "<<xx<<yy<<endl;
		printf("%d\n",-dijkstra(x,y,xx,yy));
	}
}
