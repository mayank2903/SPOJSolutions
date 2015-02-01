#include<stdio.h>
#define gtc getchar_unlocked()
int a[1000];
int x[101];
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
    int n,i,k,pos,t=0;
    long long int ans;
    n=read_int();
    while(n!=-1)
    {
        for(i=n;i>=0;i--)
        a[i]=read_int();
        k=read_int();
        for(i=0;i<k;i++)
        x[i]=read_int();
        printf("Case %d:\n",++t);
        for(i=0;i<k;i++)
        {
            //evaluate p(x) for all x[i]
            pos=n-1;ans=a[n]*x[i];
            while(pos>0)
            {
                ans=(ans+a[pos])*x[i];
                pos--;
            }
            ans+=a[pos];
            printf("%lld\n",ans);
        }
        n=read_int();
    }
    return 0;
}
