#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dp[100001];
int prev[300];
char str[100001];
int main()
{
    int t, len;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%s",str+1);
        len = strlen(str+1);
        
        memset(prev, 0, sizeof prev);
            
        dp[0] = 1;
        for(int i = 1; str[i]; i++)
        {
            dp[i] = dp[i-1] << 1;
            
            if(prev[str[i]])
                dp[i] -= dp[prev[str[i]] - 1];
                
            prev[str[i]] = i;
            
            while(dp[i] < 0) dp[i] += mod;
            if(dp[i] > mod) dp[i] %= mod;
            
            //cout<<dp[i]<<endl;
        }
        
        printf("%lld\n",dp[len]);
    }
    
    return 0;
}
