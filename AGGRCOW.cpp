#include<stdio.h>
#include<algorithm>
using namespace std;
int x[100001];
int c,n;
bool f(int d)
{
    int pos=0,cows=1,i;
    for(i=1;i<n;i++)
    {
        if(x[i]-x[pos]>=d)
        {
            pos=i;
            cows++;
            if(cows==c)return true;
        }
    }
    return false;
}
int bincalc()
{
    int l=x[0],r=x[n-1],ans=0,mid;
    while(l<r)
    {
        mid=l+(r-l)/2;
        if(f(mid)==true)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid;
    }
    return ans;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        sort(x,x+n);
        printf("%d\n",bincalc());
    }
    return 0;
}
