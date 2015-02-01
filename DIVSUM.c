#include<stdio.h>
int marked[500001];
int primes[41539];
long long int ans[500001];
long long int power(long long int a, int pow)
{
    long long int ans=1;
    if(pow==0)return 1;
    if(pow==1)return a;
    while(pow)
    {
        if(pow&1)ans*=a;
        a*=a;pow>>=1;
    }
    return ans;
}
void sieve()
{
    int k=0,i,j;
    marked[1]=1;
    for(i=2;i<=707;i++)
    {
        if(!marked[i])
        {
            for(j=i*i;j<=500000;j+=i)
            {
                marked[j]=1;
            }
        }
    }
    k=0;
    for(i=2;i<=500000;i++)
    {
        if(marked[i]==0)primes[k++]=i;
    }
}
int main()
{
    int t,n,i,m,pow;
    sieve();
    ans[1]=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        //prime:
        if(!marked[n])printf("1\n");
        //not prime:
        else if(ans[n])printf("%lld\n",ans[n]);
        else
        {
            ans[n]=1;
            int nn=n;
            for(i=0;primes[i]<=nn;i++)
            {
                pow=0;
                if(nn%primes[i]==0){
                while(nn%primes[i]==0)
                {
                    nn/=primes[i];
                    pow++;
                }
                ans[n]*=power((long long int)primes[i],pow+1)-1;
                ans[n]/=primes[i]-1;
                }
            }
            ans[n]-=n;
            printf("%lld\n",ans[n]);
        }
    }
    return 0;
}
