#include<stdio.h>
int main()
{
	int i,n;
	int f[50],g[50];
	f[0]=1;f[1]=0;
	g[0]=0;g[1]=1;
	for(i=2;i<50;i++)
	{
		f[i]=f[i-2]+2*g[i-1];
		g[i]=f[i-1]+g[i-2];
	}
	scanf("%d",&n);
	while(n!=-1)
	{
		printf("%d\n",f[n]);
		scanf("%d",&n);
	}
	return 0;
}
