#include<stdio.h>
int main()
{
	int t,n,ans,k=0,i;
	int arr[32];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)printf("%d\n",n);
		else
		{
			k=0;
			while(n!=0)
			{
				arr[k++]=n&1;
				n>>=1;
			}
			ans=0;
			for(i=0;i<k;i++)
			{
				if(arr[i])
				ans+=1<<(k-1-i);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
