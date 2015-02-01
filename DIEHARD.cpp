/*
 * diehard.cpp
 *
 *  Created on: Dec 27, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
#define air 1
#define water 2
#define fire 3
using namespace std;
int dp[4][2000][2000];
int costs[4][2] = { {0,0}, {3,2}, {-5,-10}, {-20,5} };
int into(int element, int H, int A)
{
	if(H<=0 || A<=0)
		return 0;
	if(dp[element][H][A]!=-1)
		return dp[element][H][A];
	int ans=0;
	for(int i=1;i<=3;i++)
	{
		if(i==element)
			continue;
		int val = 1 + into(i,H+costs[i][0], A+costs[i][1]);
		if(val>ans)
			ans=val;
	}
	return dp[element][H][A] = ans;
}
int main()
{
	int t,H,A;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&H,&A);
		memset(dp, -1, sizeof dp);
		int a = into(air, H, A);
		int w = into(water, H, A);
		int f = into(fire, H, A);
		printf("%d\n",max(a,max(w,f))-1);
	}
	return 0;
}
