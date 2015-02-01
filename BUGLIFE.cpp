#include <bits/stdc++.h>
using namespace std;
// 0 - no color
// 1 - black
//-1 = red
class Graph
{
    public:
    int *color;
    int n;
    list<int> *adj;
    Graph(int x)
    {
        n=x;
        color = new int[n];
        fill_n(color,n,0);
        adj = new list<int>[n];
    }
    void add(int i,int j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    int bfs(int s)
    {
        color[s]=-1;
        list<int> q;
        q.push_back(s);
        while(!q.empty())
        {
            int x=q.front();
            q.pop_front();
            list<int>::iterator i;
            for(i=adj[x].begin();i!=adj[x].end();i++)
            {
                if (!color[*i])
                    {
                        color[*i]= (color[x]==-1) ? 1 : -1;
                        q.push_back(*i);
                    }
                else if (color[*i]==color[x])
                    return 0;
            }
        }
        return 1;
    }
    int bfshelper()
    {
        int ans=1;
        for(int i=0;i<n;i++)
            if(!color[i])
                ans*=bfs(i);
        return ans;
    }
};
int main()
{
    int n;
    int num=1;
    scanf("%d",&n);
    while (n--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        Graph g(x);
        while (y--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            g.add(a-1,b-1);
        }
        int v=g.bfshelper();
        printf("Scenario #%d:\n",num++);
        if (v)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
    }
    return 0;
}
