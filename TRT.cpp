#include<stdio.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
int ans[2001][2001];
int v[2001];
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int maxval(int l, int r, int age)
{
    if(l>r)return 0;
    if(l==r)
    {
        if(ans[l][r]!=0)return ans[l][r];
        ans[l][r]=age*v[l];
        return ans[l][r];
    }
    if(ans[l][r]!=0)
    return ans[l][r];
    ans[l][r]=max(v[l]*age+maxval(l+1,r,age+1), v[r]*age+maxval(l,r-1,age+1));
    return ans[l][r];
}
int main()
{
    int n,i;
    n=read_int();
    for(i=0;i<n;i++)
    {
        v[i]=read_int();
    }
    printf("%d\n",maxval(0,n-1,1));
    return 0;
}
