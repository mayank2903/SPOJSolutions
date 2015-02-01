#include<stdio.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
int a[2001];
int read_int()
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
    int n,i,ans,index,nmin1,j,sum;
    n=read_int();
    while(n!=0)
    {
        for(i=0;i<n;i++)
        {
            a[i]=read_int();
        }
        sort(a,a+n);
        nmin1=n-1;ans=0;
        for(i=0;i<nmin1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                sum=a[i]+a[j];
                index=upper_bound(a,a+n,sum)-a;
                ans+=(n-index);
            }
        }
        printf("%d\n",ans);
        n=read_int();
    }
    return 0;
}
