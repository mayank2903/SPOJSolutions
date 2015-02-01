#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[1001];
bool visited[1001];
int dijkstra(int src, int dest)
{
    if(src==dest)
        return 0;
    memset(visited, false, sizeof visited);
    priority_queue<pair<int, int> > qq;
    qq.push(make_pair(0, src));
    while(!qq.empty())
    {
        pair<int, int> edge = qq.top();
        qq.pop();
        int wt = edge.first;
        int v = edge.second;
        if(v==dest)
            return -wt;
        if(visited[v]==true)
            continue;
        visited[v]=true;
        for(int i=0;i<adj[v].size();i++)
        {
            qq.push(make_pair(wt - adj[v][i].second, adj[v][i].first));
        }
    }
    return INT_MAX;
}
int main()
{
    int n,e,t,m,a,b,w;
    cin>>n>>e>>t>>m;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int time = dijkstra(i,e);
        if(time<=t)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
