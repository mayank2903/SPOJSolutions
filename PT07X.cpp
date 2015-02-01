#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int dp[100001][2];
int cover(int cur, int parent, bool parentCovered)
{
    if(dp[cur][parentCovered]!=-1)
        return dp[cur][parentCovered];
    int a = 1, b = 0;
    for(int i=0;i<adj[cur].size();i++)
    {
        int u=adj[cur][i];
        if(u!=parent)
        {
            if(parentCovered)
                b+=cover(u,cur,false);
            a+=cover(u, cur, true);
        }
    }
    if(parentCovered)
        return dp[cur][parentCovered] = min(a,b);
    else return dp[cur][parentCovered] = a;
}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp, -1, sizeof dp);
    int x=1,y=0;
    for(int i=0;i<adj[1].size();i++)
    {
        x+=cover(adj[1][i], 1, true);
        y+=cover(adj[1][i], 1, false);
    }
    cout<<min(x,y)<<endl;
    return 0;
}
