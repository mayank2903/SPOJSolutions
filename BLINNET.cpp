#include<bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > >el;
int parent[10001];
int findp(int u)
{
    if(u == parent[u])
        return u;
    int p = findp(parent[u]);
    return parent[u] = p;
}
void connect(int u, int v)
{
    parent[findp(u)] = parent[findp(v)];
}
int mst(int n)
{
    if(n==0)
        return 0;
    sort(el.begin(), el.end());
    int total = 0;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    int cost = 0;
    for(int i=0;total!=n-1;i++)
    {
        int u = el[i].second.first;
        int v = el[i].second.second;
        int wt = el[i].first;
        if(findp(u) == findp(v))
            continue;
        connect(u,v);
        cost += wt;
        total++;
    }
    return cost;
}
int main()
{
    int t,n,m,a,b;
    string temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        el.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>temp>>m;
            for(int j=0;j<m;j++)
            {
                cin>>a>>b;
                el.push_back(make_pair(b, make_pair(i,a)));
            }
        }
        cout<<mst(n)<<endl;
    }
    return 0;
}
