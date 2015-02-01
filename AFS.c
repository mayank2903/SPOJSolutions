#include<stdio.h>
long long int a[1000001];
int main()
{
	int t,n;
	long long int i,j;
	for(i=1;i<1000001;i++)
	{
		
		a[i]=1;
	}
	a[0]=a[1]=0;
	
	//seiving
	for(i=2;i<=1000;i++)
	{
			for(j=2*i;j<=1000000;j=j+i)
			{
				if(j==i*i)
				a[j]+=i;
				
				else if(j<i*i)
				 continue;
				 
				else
				a[j]+=i+j/i;
			}
	
		a[i]+=a[i-1];
	}
	
	for(i=1001;i<=1000000;i++)
	a[i]+=a[i-1];
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		printf("%lld\n",a[n]);
	}
	return 0;
}
