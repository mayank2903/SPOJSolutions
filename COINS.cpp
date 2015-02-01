#include<stdio.h>
#include<algorithm>
using namespace std;
long long int maxcost[10000001];
inline long long int max_val(long long int a)
{
	if(a<12)return a;
	if(a>10000000)
	return max(a,max_val(a>>1)+max_val(a/3)+max_val(a>>2));
	if(maxcost[a]!=0)return maxcost[a];
	else
	{
		maxcost[a]=max(a,max_val(a>>1)+max_val(a/3)+max_val(a>>2));
		return maxcost[a];
	}
}
int main()
{
	long long int n,val,max;
	while(scanf("%lld",&n)>0)
	{
		max=n;
		val=max_val(n>>1)+max_val(n/3)+max_val(n>>2);
		if(val>max)max=val;
		printf("%lld\n",max);
	}
	return 0;
}
