#include<stdio.h>
int sumD(long long int n)
{
	int sum=0;
	while(n!=0)
		{sum+=n%10;
	n/=10;}
	return sum;
}
int main()
{
	int t;
	long long int n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=n;;i++)
		{
			if(i%sumD(i)==0)
				break;
		}
		printf("%lld\n",i);
	}
	return 0;
}
