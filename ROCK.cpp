/*
 * rock.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
char str[500];
int sum[500];
int dp[250][250];
int find(int i, int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i>j)
		return dp[i][j]=0;
	if(i==j)
		return dp[i][j]=(sum[j]-sum[i-1]==1?1:0);
	if(sum[j]-sum[i-1]==0)
		return dp[i][j]=0;
	if(sum[j]-sum[i-1] > (j-i+1-sum[j]+sum[i-1]))
		return dp[i][j]=j-i+1;
	int ans=0;
	for(int k=i;k<=j-1;k++)
	{
		dp[i][k]=find(i,k);
		dp[k+1][j]=find(k+1,j);
		int val = dp[i][k] + dp[k+1][j];
		if(val>ans)
			ans=val;
	}
	return dp[i][j]=ans;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,-1,sizeof dp);
		scanf("%s",str+1);
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1]+(str[i]=='0'?0:1);
		}
		printf("%d\n",find(1,n));
	}
	return 0;
}
