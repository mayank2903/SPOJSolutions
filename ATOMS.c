#include<stdio.h>
#include<math.h>
int main()
{
	int p;
	unsigned long long int k,n,m,t;
	unsigned long long int term1,term2;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%llu%llu%llu",&n,&k,&m);
		if(n>=m){printf("0\n");continue;}
		term1=m/n;
		t=0;
		while(term1>=k)
		{
			term1/=k;t++;
		}
		printf("%lld\n",t);
	}
	return 0;
}
