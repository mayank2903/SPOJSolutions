#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	int t;
	long long int x,g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&g);
		n=sqrt(8*g-6);
		n=(n-1)/2;
		x=(long long int)n;
		printf("%lld\n",x);
	}
	return 0;
}
