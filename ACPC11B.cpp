#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<limits.h>
using namespace std;
int main()
{
	int t,n,i,j,mindiff,n1,n2;
	int a1[1000],a2[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n1);
		for(i=0;i<n1;i++)
		scanf("%d",a1+i);
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
		scanf("%d",a2+i);
		mindiff=INT_MAX;
		for(i=0;i<n1;i++)
		{
			for(j=0;j<n2;j++)
			{
				mindiff=min(mindiff,abs(a1[i]-a2[j]));
			}
		}
		printf("%d\n",mindiff);
	}
	return 0;
}
