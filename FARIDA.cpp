#include<bits/stdc++.h>
using namespace std;
long long int coins[10001];
long long int dp[10001];
long long int calc(long long int n)
{
    long long int tmp=0,ans=0;
    
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=coins[i-1];
        
        //this basically calculates max from all elements two steps back.
        if(i>=2)
        tmp=max(tmp,dp[i-2]);
        
        dp[i]+=tmp;
        ans=max(ans,dp[i]);
    }
    
    return ans;
}
int main()
{
    int t,n;
    
    cin>>t;
    
    for(int tt=1;tt<=t;tt++)
    {
        
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>coins[i];
        }
        cout<<"Case "<<tt<<": "<<calc(n)<<endl;
    }
    
    return 0;
}
