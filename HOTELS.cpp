#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
typedef long long ll;
using namespace std;
int a[300001];
int main()
{
	int n,m;
	
	s(n);s(m);
	rep(i,n)
	s(a[i]);
	long long ans=0,cur=0;
	int pos=0;
	rep(i,n)
	{
		if(cur+a[i]<=m)
		{
			cur+=a[i];
		}
		else
		{
			cur+=a[i];
			while(cur>m)
			{
				cur-=a[pos];
				pos++;
			}
		}
		if(cur>ans)
			ans=cur;
	}
	printf("%lld\n",ans);
	return 0;
}
