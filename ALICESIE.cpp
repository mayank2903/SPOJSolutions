#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
/*
bool marked[1000001];
int primes[78498];
int k;
void sieve()
{
    int i,j;
    k=0;
    marked[0]=marked[1]=true;
    for(i=2;i<=1000;i++)
    {
        if(!marked[i])
        {
            primes[k++]=i;
            for(j=i*i;j<=1000000;j+=i)
            marked[j]=true;
        }
    }
    for(i=1001;i<1000000;i++)
    if(!marked[i])primes[k++]=i;
    //printf("%d primes\n",k);
}
*/
int main()
{
    int t,pos,n;
//    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",(n+1)/2);
    }
    return 0;
}
