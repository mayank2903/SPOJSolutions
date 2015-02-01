#include<stdio.h>
#include<math.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
int a[1000][1000];
int in[1000];
int out[1000];
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
    int n,sum,i,j,ans,t;
    t=1;
    n=read_int();
    while(n!=0)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            in[i]=out[i]=0;
        for(j=0;j<n;j++)
        {
            a[i][j]=read_int();
            sum+=a[i][j];
        }
        }
        //printf("sum=%d\n",sum);
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                //i gives j an amount equal to a[i][j]..so in[j]+=a[i][j]
                if(a[i][j]!=0)
                {
                    in[j]+=a[i][j];
                    out[i]+=a[i][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            ans+=abs(in[i]-out[i]);
        }
        printf("%d. %d %d\n",t,sum,ans>>1);
        t++;
        n=read_int();
    }
    return 0;
}
