#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int stones[100][100];
int a[100][100];
int main()
{
	int t,h,w,i,j,maxi;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&a[i][j]);
				if(i==0)stones[i][j]=a[i][j];
			}
		}
		for(i=1;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				maxi=INT_MIN;
				if((j-1)>=0)
					maxi=max(maxi,stones[i-1][j-1]);
				if((j+1)<w)
					maxi=max(maxi,stones[i-1][j+1]);
				maxi=max(maxi,stones[i-1][j]);
				stones[i][j]=a[i][j]+maxi;
			}
		}
		maxi=INT_MIN;
		for(i=0;i<w;i++)
			maxi=max(maxi,stones[h-1][i]);
		printf("%d\n",maxi);
	}
	return 0;
}
