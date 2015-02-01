#include<stdio.h>
long long int a[10001];
int main()
{
    long long int t,n,sum,i,avg,ans;
    n=1;
    while(n!=-1)
    {
        scanf("%lld",&n);
        {
            if(n==-1)break;
        }
        sum=0;ans=0;avg=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",a+i);
            sum+=a[i];
        }
        avg=sum/n;
        if((avg*n)!=sum){printf("-1\n");continue;}
        for(i=0;i<n;i++)
        {
            if(a[i]>avg)ans+=(a[i]-avg);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
