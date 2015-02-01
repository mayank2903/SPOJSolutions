#include<bits/stdc++.h>
#define lol long long
using namespace std;
int mat[21][21];
long long ans[1<<21];
inline int bitCount(int n)
{
	int cnt = 0;
	while(n)
	{
		cnt += (n&1);
		n>>=1;
	}
	return cnt;
}	
int main()
{
	int t, n, x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(mat, 0, sizeof mat);
		memset(ans, 0, sizeof ans);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}
		int comb = (1<<n) - 1;
		ans[comb] = 1;
		for(int i = comb; i >= 0; i--)
		{
			int next = bitCount(i);
			//i denotes the students which have already got assignment.
			for(int j = 0; j < n; j++)
			{
				//basically i represents the bitmask denoting which assignments are complete till now.
				if(mat[next][j] == 0 || (i& (1<<j)))
					continue;
				ans[i] += ans[i | (1<<j)];
			}
		}
		printf("%lld\n",ans[0]);
	}
	return 0;
}
