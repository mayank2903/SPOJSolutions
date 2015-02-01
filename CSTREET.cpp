#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include<climits>
using namespace std;
//using kruskal.
pair<int, pair<int, int> > edges[300001];
int parent[1001];
bool hasCycle(int a, int b)
{
	int temp;
	
	//finds if theres a cycle by including the edge: (a,b).
	while(parent[a]!=a)
	{
		temp=parent[a];
		parent[a]=parent[parent[a]];
		a=temp;
	}
	
	while(parent[b]!=b)
	{
		temp=parent[b];
		parent[b]=parent[parent[b]];
		b=temp;
	}
	
	if(a==b)return true;
	
	else
	{
		parent[a]=b;
		return false;
	}
}
int main()
{
	int t,p,n,m,i,cost,ecount;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d%d",&p,&n,&m);
		
		//initializing things.
		for(i=0;i<=n;i++)
		parent[i]=i;
		
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&edges[i].second.first, &edges[i].second.second, &edges[i].first);
		}
		
		//sort based on weight.
		sort(edges,edges+m);
		
		//now traverse the edge list, and include edge if it doesnt form a cycle. continue till u get n-1 edges.
		ecount=0;i=0;cost=0;
		
		while(ecount!=n-1 && i<m)
		{
			if(!hasCycle(edges[i].second.first, edges[i].second.second))
			{
				cost+=edges[i].first;
				ecount++;
			}
			
			
			i++;
		}
		
		printf("%d\n",cost*p);
	}
	return 0;
}
