#include<stdio.h>
#include<map>
#define gtc getchar_unlocked()
using namespace std;
inline int read_int()
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
    map<int, bool> mm;
    int i,n,x,ans,k;
    n=read_int();k=read_int();
    for(i=0;i<n;i++)
    {
        x=read_int();
        mm[x]=true;
    }
    ans=0;
    for(map<int, bool>::iterator ii=mm.begin();ii!=mm.end();ii++)
    {
        ans+=(mm.find((*ii).first+k)!=mm.end())+(mm.find((*ii).first-k)!=mm.end());
    }
    printf("%d\n",ans>>1);
    return 0;
}
