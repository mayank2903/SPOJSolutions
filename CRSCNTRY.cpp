#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int> > routes;
int dp[2001][2001];
int lcs(vector<int> a, vector<int> b)
{
    for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    }
    //cout<<"lcs="<<dp[a.size()][b.size()]<<endl;
    return dp[a.size()][b.size()];
}
vector<int> alice,temp;
int main()
{
    int t,x,i,prev;
    cin>>t;
    while(t--)
    {
        alice.clear();
        temp.clear();
        for(int i=0;i<routes.size();i++)
            routes[i].clear();
        while(true)
        {
            cin>>x;
            if(x==0)
            break;
            alice.push_back(x);
        }
        prev=-1;
        while(true)
        {
            cin>>x;
            if(x==0)
            {
                if(prev==0)
                    break;
                routes.push_back(temp);
                temp.clear();
                prev=x;
                continue;
            }
            prev=x;
            temp.push_back(x);
        }
        int ans=0;
        for(int j=0;j<routes.size();j++)
        {
            ans=max(ans,lcs(alice,routes[j]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
