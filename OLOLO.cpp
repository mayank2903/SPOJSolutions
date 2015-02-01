#include<stdio.h>
int main()
{
	int n;
	int ans,x;
	scanf("%d",&n);
	ans=0;
	while(n--)
	{
		scanf("%d",&x);
		ans^=x;
	}
	printf("%d\n",ans);
	return 0;
}
