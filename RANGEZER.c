#include<stdio.h>
long int counts[10000001];
int numOfZeros(int n)
{
	int count=0;
	while(n!=0)
	{
		if(n%10==0)count++;
		n/=10;
	}
	return count;
}
int main()
{
	int t,count;
	long int a,b,i;
	counts[0]=0;
	for(i=1;i<10000001;i++)
	{
		counts[i]=counts[i-1]+numOfZeros(i);
	}
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%ld%ld",&a,&b);
		printf("%ld\n",counts[b]-counts[a-1]);
	}
	return 0;
}
