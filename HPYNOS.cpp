#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	long long int n,temp,sum,tries,r,f;
	map<long long int, int> mmap;
	scanf("%lld",&n);
	tries=0;
	temp=n;
	while(1)
	{
		sum=0;
		tries++;
		while(temp!=0)
		{
			r=temp%10;
			sum+=r*r;
			temp/=10;
		}
		if(sum==1){f=1;break;}
		else if(mmap.find(sum)!=mmap.end()){f=0;break;}
		mmap[sum]=1;
		temp=sum;
	}
	if(f)printf("%lld\n",tries);
	else printf("-1\n");
	return 0;
}
