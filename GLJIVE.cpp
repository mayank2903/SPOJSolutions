#include<stdio.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
int abs(int a)
{
	if(a<0)return -a;
	return a;
}
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
	int a[10],i,closest,temp,bitno,sum,prevdiff,newdiff,index;
	closest=0;
	for(i=0;i<10;i++)
	{
		a[i]=read_int();
		closest+=a[i];
		if(closest>=100)
		{
			if(abs(closest-100)<=abs(100-closest+a[i]))printf("%d\n",closest);
			else printf("%d\n",closest-a[i]);
			return 0;
		}
	}
	printf("%d\n",closest);
	return 0;
}
