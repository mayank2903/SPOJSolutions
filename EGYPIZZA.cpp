#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i;
	int half,quarts,threequarts,pizza,x;
	char str[4];
	half=quarts=threequarts=0;
	pizza=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		if(str[2]=='2')half++;
		else if(str[0]=='1')quarts++;
		else threequarts++;
	}
	pizza+=half/2 +(x=min(quarts,threequarts));
	half%=2;
	quarts-=x;threequarts-=x;
	if(half==0)
	{
		if(quarts>0)
		{
			pizza+=quarts/4+(quarts%4!=0);
		}
		else pizza+=threequarts;
	}
	else
	{
		if(quarts>0)
		{
			if(quarts>=2)
			{
				quarts-=2;
				half--;
				pizza++;
				pizza+=quarts/4+(quarts%4!=0);
			}
			else //quarts=1
			{
				pizza++;
				half=0;
				quarts=0;
			}
		}
		else if(threequarts>0)
		{
			pizza+=threequarts+half;
		}
		else pizza+=half;
	}
	printf("%d\n",pizza+1);
	return 0;
}
