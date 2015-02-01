#include<stdio.h>
#include<math.h>
int main()
{
	int t,i;
	long long int n,sum,x;
	long long int powers[12]={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%lld",&n);
		for(i=0;i<12;i++)
		{
			if(n<powers[i])break;
			x=n/powers[i];
			sum+=x;
		}
		printf("%lld\n",sum);
	}return 0;
}
