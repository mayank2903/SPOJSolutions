#include<stdio.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
ll max(ll a, ll b)
{
    if(a>=b)return a;
    return b;
}
int main()
{
    ll a[4],i,j,temp;
    int t=1;
    while(scanf("%lld%lld%lld%lld",a+0,a+1,a+2,a+3)!=EOF)
    {
        sort(a,a+4);
        printf("Case %d: %lld\n",t,max(a[0]+a[1],a[2]+a[3]));
        t++;
    }
    return 0;
}
