#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define mod 10000000007
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
typedef long long ll;
using namespace std;
void printbin(int x)
{
        char str[64];
        int l=0;
        while(x)
        {
            str[l++]=(x&1)+'0';
            x>>=1;
        }
        l--;
        
        for(;l>=0;l--)
        putchar(str[l]);
        
        puts("");
}
int main()
{
    int t,n,cnt,x;
    s(t);
    
    while(t--)
    {
        s(n);
        
        queue<int> q;
        
        q.push(1%n);
        cnt=0;
        
        while(1)
        {
            x=q.front();
            q.pop();
            
            cnt++;
            
            if(x==0)
            break;
            
            q.push((x*=10)%n);
            q.push((x+1)%n);
        }
        
        printbin(cnt);
    }
    
    return 0;
}
