#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<unistd.h>
using namespace std;
bool prime[10000];
int primes[1229];
int marked[10000];
queue<pair<int, int> > qq;
void sieve()
{
    int k=0,i,j;
    prime[1]=prime[0]=true;
    for(i=2;i<100;i++)
    {
        if(prime[i]==false)
        {
            primes[k++]=i;
            for(j=i*i;j<10000;j+=i)
            prime[j]=true;
        }
    }
    for(i=101;i<10000;i++)
    if(prime[i]==false)primes[k++]=i;
}
int main()
{
    int t,n1,n2,x,f,d1,d2,d3,d4,i,j;
    pair<int, int> xx;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n1,&n2);
        if(n1==n2)
        {
            printf("0\n");
            continue;
        }
        qq.push(make_pair(n1,0));f=0;
        while(1)
        {
            xx=qq.front();
            qq.pop();
            //first replacing the first digit..
            d1=xx.first/1000;
            //printf("d1=%d\n",d1);
            for(i=1;i<=9;i++)
            {
                if(i!=d1)
                {
                    x=xx.first+(i-d1)*1000;
                    if(x==n2){f=1;xx.second+=1;break;}
                    if(prime[x]==false && !marked[x])
                    {
                        marked[x]=true;
                        qq.push(make_pair(x,xx.second+1));
                        //printf("pushing %d\n",x);
                        //getchar();
                    }
                }
            }
            if(f==1)break;
            //replacing second digit..
            d2=(xx.first%1000)/100;
            //printf("d2=%d\n",d2);
            for(i=0;i<10;i++)
            {
                if(i!=d2)
                {
                    x=xx.first+(i-d2)*100;
                    if(x==n2){f=1;xx.second+=1;break;}
                    if(prime[x]==false && !marked[x])
                    {
                        marked[x]=true;
                        qq.push(make_pair(x,xx.second+1));
                        //printf("pushing %d\n",x);
                        //getchar();
                    }
                }
            }
            if(f==1)break;
            //replacing third digit..
            d3=(xx.first%100)/10;
            //printf("d3=%d\n",d3);
            for(i=0;i<10;i++)
            {
                if(i!=d3)
                {
                    x=xx.first+(i-d3)*10;
                    if(x==n2){f=1;xx.second+=1;break;}
                    if(prime[x]==false && !marked[x])
                    {
                        marked[x]=true;
                        qq.push(make_pair(x,xx.second+1));
                        //printf("pushing %d\n",x);
                        //getchar();
                    }
                }
            }
            if(f==1)break;
            //replacing fourth digit..
            d4=xx.first%10;
            //printf("d4=%d\n",d4);
            for(i=0;i<10;i++)
            {
                if(i!=d4)
                {
                    x=xx.first+(i-d4);
                    if(x==n2){f=1;xx.second+=1;break;}
                    if(prime[x]==false && !marked[x])
                    {
                        marked[x]=true;
                        qq.push(make_pair(x,xx.second+1));
                        //printf("pushing %d\n",x);
                        //getchar();
                    }
                }
            }
            if(f==1)break;
        }
        if(f==0)
        printf("Impossible\n");
        else printf("%d\n",xx.second);
        while(!qq.empty())
        qq.pop();
        for(i=0;i<10000;i++)marked[i]=false;
    }
    return 0;
}
