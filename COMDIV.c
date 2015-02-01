#include<stdio.h>
#include<stdbool.h>
#define gtc getchar_unlocked()
int primes[78498];
bool marked[1000001];
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
inline void fastWrite(int a)
{
    char snum[20];
    int i=0;
    do
    {
        snum[i++]=a%10+48;
        a=a/10;
    }
    while (a);
    i=i-1;
    while (i>=0)
        putchar(snum[i--]);
    putchar('\n');
}
int gcd(int a, int b)
{
    int t1,t2;
    if(b==0)return a;
    while(b)
    {
        t1=b;
        t2=a%b;
        a=t1;b=t2;
    }
    return a;
}
inline int maxdiv(int* a, int factor)
{
    int pow=0;
    while((*a)%factor==0)
    {
        pow++;
        (*a)/=factor;
    }
    return pow;
}
void sieve()
{
    int k,i,j;
    k=0;marked[0]=marked[1]=true;
    for(i=2;i<998;i++)
    {
        if(!marked[i])
        {
            primes[k++]=i;
            for(j=i*i;j<=1000000;j+=i)
            marked[j]=true;
        }
    }
    for(i=1001;i<=999997;i++)
    if(!marked[i])primes[k++]=i;
    //printf("%d primes\n",k);
}
int main()
{
    int t,a,b,g,ans,pow,i;
    sieve();
    t=read_int();
    while(t--)
    {
        a=read_int();b=read_int();
        if((!marked[a]) && (!marked[b]))
        {
            puts("1");continue;
        }
        else if(marked[a] && !marked[b])
        {
            fastWrite(maxdiv(&a,b)+1);
            continue;
        }
        else if(marked[b] && !marked[a])
        {
            fastWrite(maxdiv(&b,a)+1);
            continue;
        }
        g=gcd(a,b);
        i=0;ans=1;
        while(primes[i]<=g)
        {
            if(g%primes[i]==0)
            {
                //printf("factor=%d\n",primes[i]);
                pow=1;
                while(g%primes[i]==0)
                {
                    pow++;
                    g/=primes[i];
                }
                //printf("pow=%d\n",pow);
                ans*=pow;
            }
            i++;
        }
        fastWrite(ans);
    }
    return 0;
}
