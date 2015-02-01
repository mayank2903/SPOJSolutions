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
#define gtc getchar_unlocked()
using namespace std;
bool prime[1000001];
bool cfre[1000001];
int indx[1000001];
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
void sieve()
{
	int i,j,cube;
	
	prime[1]=prime[0]=true;	//not prime
	
	for(i=2;i<1000;i++)
	{
		if(!prime[i])	//is a prime
		{
			cube=i*i*i;
			for(j=i*i;j<=1000000;j+=i)
			{
				prime[j]=true;	//means not prime
				
				if(j>=cube && j%cube==0)
				cfre[j]=true;	//means not cube free.
			}
		}
	}
	
	for(i=1;i<=1000000;i++)
	{
		indx[i]=indx[i-1]+(cfre[i]==false);
	}
}
int main()
{
	int t,tt,n;
	
	sieve();
	t=read_int();
	
	tt=t;
	while(t--)
	{
		n=read_int();
		
		printf("Case %d: ",tt-t);
		
		if(cfre[n])
		puts("Not Cube Free");
		
		else printf("%d\n",indx[n]);
	}
	return 0;
}
