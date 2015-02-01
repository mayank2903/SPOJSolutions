#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	if(n&(n-1))//doesnt stop
		printf("NIE\n");
	else printf("TAK\n");
	return 0;
}
