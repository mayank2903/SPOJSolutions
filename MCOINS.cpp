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
typedef long long int ll;
using namespace std;
bool ans[1000005];
int main()
{
	int k,l,m,i,x;
	
	scanf("%d%d%d",&k,&l,&m);
	for(i=0;i<1000005;i++)
	{
		if(i==0)
		ans[i]=false;	//lost
		
		else if(i-1>=0 && ans[i-1]==false)
		ans[i]=true;
		
		else if(i-k>=0 && ans[i-k]==false)
		ans[i]=true;
		
		else if(i-l>=0 && ans[i-l]==false)
		ans[i]=true;
	}
	
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		printf("%c",ans[x]?'A':'B');
	}
	
	return 0;
}
