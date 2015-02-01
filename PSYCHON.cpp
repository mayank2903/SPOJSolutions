#include <iostream>
#include <cmath>
using namespace std;
#define ll unsigned long long
#define MAX 10000000
#define LMT 3200
unsigned flag[MAX/64];
unsigned prime[664581], total;
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
void sieve()
{
        unsigned i, j, k;
        for(i=3;i<LMT;i+=2)
                if(!chkC(i))
                        for(j=i*i,k=i<<1;j<MAX;j+=k)
                                setC(j);
        prime[1] = 2;
    
        for(i=3,j=2;i<MAX;i+=2)
        {
                if(!chkC(i))
                {
                    prime[j++] = i;
                }
        }               
        total = j;
}
int f(int a)
{
    unsigned int v=0;
    int h=a;
    int cntev=0;
    int cntod=0;
    for(int j=1,t=prime[j];t*t<=h; t = prime[++j])
    {
                v=0;
                if(h%t==0)
                {
                       
                        while(h%t==0)
                        {
                                v++;
                                h/=t;
                        }
                        if(v%2==0)
                             cntev++;
                        else
                             cntod++;
                       
                }
              
                  
                if(h==1)
                    break;
    }
    if(h!=1)
       cntod++;
    if(cntev>cntod)
       return 1;
    else
       return 0;
    
}
int main()
{
     sieve();
     int t,a;
     scanf("%d",&t);
     while(t--)
     {
       scanf("%d",&a);
       int cnt=f(a);
       if(cnt==1)
           printf("Psycho Number\n");
       else
           printf("Ordinary Number\n");
     }
     return 0;
}
