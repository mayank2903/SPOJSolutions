#include<stdio.h>
#include<utility>
#include<algorithm>
std::pair<int, int> arr[10000001];
int main()
{
	int t,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int c=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			arr[c++]=std::make_pair(a,1);
			arr[c++]=std::make_pair(b,0);
		}
		std::sort(arr,arr+c);
		int ans=0,ctr=0;
		for(int i=0;i<c;i++)
		{
			if(arr[i].second == 1)
				ctr++;
			else ctr--;
			if(ctr>ans)
				ans=ctr;
		}
		printf("%d\n",ans);
	}
	return 0;
}
