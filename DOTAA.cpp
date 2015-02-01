#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,m,d,tot,x,i;
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		scanf("%d%d%d",&n,&m,&d);
		//printf("n=%d m=%d d=%d\n",n,m,d);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x%d==0)tot+=x/d-1;
			else tot+=x/d;
		}
		if(tot>=m)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
