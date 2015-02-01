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
#define PI 2*acos(0.0)
#define g 9.806
typedef long long int ll;
using namespace std;
int main()
{
	int i,t;
	
	double num,theta,x,v;
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		scanf("%lf%lf",&x,&v);
		
		printf("Scenario #%d:",i+1);
		
		num=g*x;
		num/=v*v;
		
		if(num<-1 || num>1)
		puts(" -1");
		else
		{
			theta=asin(num)/2.0;
			printf(" %.2lf\n",theta*180.0/(PI));
		}
	}
	return 0;
}
