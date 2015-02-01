#include<stdio.h>
int a[1000001];
int main()
{
	int t,n,i,count,pos;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		pos=0;count=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==a[pos])
				count++;
			else count--;
			if(count==0){pos=i;count=1;}
		}
		count=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==a[pos])count++;
		}
		if(count>(n/2))printf("YES %d\n",a[pos]);
		else printf("NO\n");
	}
	return 0;
}
