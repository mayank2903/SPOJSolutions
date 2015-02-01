#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
struct edge{
        int to, weight;
        edge(){}
        edge(int t,int w) :to(t),weight(w){}
        bool operator < (const edge &that) const{
                return weight > that.weight;
        }
};
 
const int MAXNODES = 10002;
vector <edge> g[MAXNODES];
int d[MAXNODES], p[MAXNODES];
 
void Dijkstra(int s,int t,int n)
{
        for (int i = 0; i<=n;++i){
                d[i] = INT_MAX;
                p[i] = -1;
        }
        d[s] = 0;
        priority_queue <edge> q;
        q.push(edge(s,0));
        while(q.size()){
                int node = q.top().to;
                int dist = q.top().weight;
                q.pop();
               
                if (dist > d[node]) continue;
                if (node == t) break;
                for (int i = 0; i<g[node].size();++i){
                        int to = g[node][i].to;
                        int w_extra = g[node][i].weight;
                        if (dist + w_extra < d[to]){
                                d[to] = dist + w_extra;
                                p[to] = node;
                                q.push(edge(to,d[to]));
                        }
                }
        }
        printf("%d\n",d[t]);
}
int main()
{
        int t,n,number,vecinos,to,cost,paths;
        string city,begin,end;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                map <string,int> names;
                number = 0;
                for (int i = 0; i<=n;++i) g[i].clear();
                for (int i = 0; i<n;++i){
                        cin >> city;
                        names.insert(pair<string,int>(city,++number));
                        scanf("%d",&vecinos);
                        for (int j = 0; j<vecinos;++j){
                                scanf("%d %d",&to,&cost);
                                g[number].push_back(edge(to,cost));
                        }
                }
                scanf("%d",&paths);
                for (int i = 0; i<paths;++i){
                        cin >> begin >> end;
                        Dijkstra(names.find(begin)->second,names.find(end)->second,n);
                }
        }
        return 0;
}
