#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&n);
	while(n!=0)
	{
		printf("%d\n",n*(n+1)*(n*2+1)/6);
		scanf("%d",&n);
	}
	return 0;
}
