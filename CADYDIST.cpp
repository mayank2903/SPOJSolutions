#include<stdio.h>
#include<functional>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
typedef long long int ll;
ll p[100001],c[100001];
inline ll read_int()
{
    register ll noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int read()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int main()
{
    int n,i;ll ans;
    n=read();
    while(n!=0)
    {
        for(i=0;i<n;i++)
        c[i]=read_int();
        for(i=0;i<n;i++)
        p[i]=read_int();
        sort(c,c+n,less<long long int>());
        sort(p,p+n,greater<long long int>());
        ans=0;
        for(i=0;i<n;i++)
        {
            ans+=c[i]*p[i];
        }
        printf("%lld\n",ans);
        n=read();
    }
    return 0;
}
