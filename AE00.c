#include<stdio.h>
int numOfFact(int n)
{
	int i,count=0;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)count++;
	}
	return count;
}
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		count+=numOfFact(i);
	}
	printf("%d\n",count);
	return 0;
}
