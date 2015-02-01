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
int d[2000];
bool possible(int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(d[i+1]-d[i]>200)
		return false;
	}
	
	if(2844-2*d[n-1]>200)
	return false;
	
	return true;
}
int main()
{
	int n,i;
	
	scanf("%d",&n);
	
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&d[i]);
		}
		
		sort(d,d+n);
		
		if(possible(n))
		puts("POSSIBLE");
		
		else
		puts("IMPOSSIBLE");
		
		scanf("%d",&n);
	}
	return 0;
}
