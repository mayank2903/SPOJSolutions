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
ll ans=0;
char str[30];
void calc(char* str, int prev, int i, int len)
{
	int x,j;
	
	if(i==len)
	ans++;
	
	x=0;
	for(j=i;j<len;j++)
	{
		x+=str[j]-'0';
		if(x>=prev)
		calc(str,x,j+1,len);
	}
}
int main()
{	
	int prev=-1,cas;
	char str[30];
	
	scanf("%s",str);
	cas=0;
	while(str[0]!='b')
	{
		ans=0;cas++;
		calc(str, prev, 0, strlen(str));
		printf("%d. %lld\n",cas,ans);
		
		scanf("%s",str);
	}
	
	return 0;
}
