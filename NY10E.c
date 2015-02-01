#include<stdio.h>
typedef long long int ll;
ll a[65][10];
int L;
ll dp()
{
    int l,d,i;
    for(l=0;l<=L;l++)
    {
        for(d=0;d<=9;d++)
        {
            if(l<=1)a[l][d]=l;
            else
            {
                a[l][d]=0;
                for(i=0;i<=d;i++)
                {
                    a[l][d]+=a[l-1][i];
                }
            }
        }
    }
    ll sum=0;
    for(i=0;i<=9;i++)sum+=a[L][i];
    return sum;
}
int main()
{
    int t,no;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&no,&L);
            printf("%d %lld\n",no,dp());
        }
        return 0;
}
