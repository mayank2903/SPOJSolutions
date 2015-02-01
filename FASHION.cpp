#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,sum,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int boys[n];
		int girls[n];
		for(i=0;i<n;i++)
			scanf("%d",&boys[i]);
		for(i=0;i<n;i++)
			scanf("%d",&girls[i]);
		sort(boys,boys+n);
		sort(girls,girls+n);
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=boys[i]*girls[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
