#include<stdio.h>
int main()
{
	int t,tt;
	long long int r;
	scanf("%d",&tt);
	for(t=1;t<=tt;t++)
	{
		scanf("%lld",&r);
		r=4*r*r;
		printf("Case %d: %lld.25\n",t,r);
	}
	return 0;
}
