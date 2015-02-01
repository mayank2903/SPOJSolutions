#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int g,b,mini,maxi;
	scanf("%d%d",&g,&b);
	while(g!=-1)
	{
		mini=min(g,b);
		maxi=max(g,b);
		printf("%d\n",maxi/(mini+1)+(maxi%(mini+1)!=0));
		scanf("%d%d",&g,&b);
	}
	return 0;
}
