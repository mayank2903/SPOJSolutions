#include<stdio.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int main()
{
	int t,sum,i,toborrow,numfrnds,tt;
	int stamps[1001];
	t=read_int();
	tt=t;
	while(t--)
	{
		toborrow=read_int();
		numfrnds=read_int();
		sum=0;
		for(i=0;i<numfrnds;i++)
		{
			stamps[i]=read_int();
			sum+=stamps[i];
		}
		if(sum<toborrow)
		{
			printf("Scenario #%d:\nimpossible\n\n",tt-t);
			continue;
		}
		sort(stamps,stamps+numfrnds);
		//for(i=0;i<numfrnds;i++)printf("stamps%d\n",stamps[i]);
		sum=0;
		for(i=numfrnds;i>=1;i--)
		{
			sum+=stamps[i-1];
			if(sum>=toborrow)break;
		}
		printf("Scenario #%d:\n%d\n\n",tt-t,numfrnds-i+1);
	}
	return 0;
}
