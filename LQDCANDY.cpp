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
int main()
{
	int t,c;
	ll len,n,nn;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%lld",&n);
		
		if((n&(n-1))==0)
		{
			printf("%lld 0\n",n);
			continue;
		}
		
		len=1;nn=n;
		while(nn)
		{
			nn>>=1;
			len<<=1;
		}
		
		printf("%lld ",len);
		c=0;
		while(n)
		{
			if(len>n)
			{
				len>>=1;
				c++;
				continue;
			}
			
			else if(len<=n)
			{
				n-=len;
			}
		}
		printf("%d\n",c);
		
	}
	return 0;
}
