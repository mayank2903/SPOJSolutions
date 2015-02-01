#include<stdio.h>
#include<algorithm>
#include<limits.h>
#define gtc getchar_unlocked()
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
using namespace std;
int a[20001];
int main()
{
	int t,n,k,i,mini;
	t=read_int();
	while(t--)
	{
		n=read_int();
		k=read_int();
		for(i=0;i<n;i++)a[i]=read_int();
		sort(a,a+n);
		mini=INT_MAX;
		for(i=0;i<=n-k;i++)
		{
			mini=min(mini,a[i+k-1]-a[i]);
		}
		printf("%d\n",mini);
	}
	return 0;
}
