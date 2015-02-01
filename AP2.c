#include<stdio.h>
int main()
{
	long long int t1,t2,sum,n,d,i,t;
	scanf("%lld",&t);
	while(t--){
	scanf("%lld%lld%lld",&t1,&t2,&sum);
	n=2*sum;
	n/=(t1+t2);
	d=(t2-t1)/(n-5);
	printf("%lld\n",n);
	printf("%lld %lld %lld ",t1-2*d,t1-d,t1);
	for(i=1;i<=n-3;i++)
	{
		printf("%lld ",t1+i*d);
	}
	printf("\n");
}
	return 0;
}
