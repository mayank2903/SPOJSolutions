#include<stdio.h>
int reverse(int n)
{
	int r,rev=0;
	while(n!=0)
	{
		r=n%10;
		n/=10;
		rev=rev*10+r;
	}
	return rev;
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",reverse(reverse(a)+reverse(b)));
	}
	return 0;
}
