#include<stdio.h>
int calc(int n, int prev, int len)
{
	if(len==n)
	return 1;
	
	if(prev==0)
	return calc(n,0,len+1)+calc(n,1,len+1);
	
	else if(prev==1)
	return calc(n,0,len+1)+calc(n,1,len+1)+calc(n,2,len+1);
	
	else return calc(n,1,len+1)+calc(n,2,len+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	
	printf("%d\n",calc(n,0,1)+calc(n,1,1)+calc(n,2,1));
}
