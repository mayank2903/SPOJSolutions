#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int e,ee,f,ff,s,ss,m,mm,ans,maxratio;
	scanf("%d%d%d%d%d%d%d%d",&e,&f,&s,&m,&ee,&ff,&ss,&mm);
	while(e!=-1)
	{
		maxratio=0;
		maxratio=max(max(ceil((0.0+e)/ee),ceil((0.0+f)/ff)),max(ceil((s+0.0)/ss),ceil((0.0+m)/mm)));
		ans=maxratio*ee-e;printf("%d ",ans);
		ans=maxratio*ff-f;printf("%d ",ans);
		ans=maxratio*ss-s;printf("%d ",ans);
		ans=maxratio*mm-m;printf("%d\n",ans);
		scanf("%d%d%d%d%d%d%d%d",&e,&f,&s,&m,&ee,&ff,&ss,&mm);
	}
	return 0;
}
