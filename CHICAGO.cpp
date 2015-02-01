#include<bits/stdc++.h>
using namespace std;
bool visited[101];
vector<pair<int, int> >adj[101];
double dijkstra(int src, int dest)
{
	pair<double, int> edge;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > >qq;
	qq.push(make_pair(-100.0,src));
	while(true)
	{
		edge = qq.top();
		qq.pop();
		int v = edge.second;
		double wt = edge.first;
		//printf("vertex=%d, cost=%lf\n",v,wt);
		if(visited[v])
			continue;
		else if(v==dest)
			return wt;
		visited[v] = true;
		for(int i=0;i<adj[v].size();i++)
		{
			if(visited[adj[v][i].first])
				continue;
			qq.push(make_pair(wt*adj[v][i].second/100.0, adj[v][i].first));
		}
	}
}
int main()
{
	int n,m,a,b,p;
	while(true)
	{
		scanf("%d",&n);
		if(n==0)break;
		scanf("%d",&m);
		memset(visited, false, sizeof visited);
		for(int i=0;i<=100;i++)adj[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&p);
			adj[a].push_back(make_pair(b,p));
			adj[b].push_back(make_pair(a,p));
		}
		printf("%.6lf percent\n",abs(dijkstra(1,n)));
	}
	return 0;
}
