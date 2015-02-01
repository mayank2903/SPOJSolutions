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
ll gcd(ll a, ll b)
{
	return (b==0)?a:gcd(b,a%b);
}
long long int lcm(ll a, ll b)
{
	ll l=a*b;
	ll g=gcd(a,b);
	
	return l/=g*g;
}
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	while(a&&b)
	{
		printf("%lld\n",lcm(a,b));
		
		scanf("%lld%lld",&a,&b);
	}
	
	return 0;
}
