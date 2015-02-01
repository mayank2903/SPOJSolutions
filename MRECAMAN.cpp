#include<stdio.h>
#include<map>
using namespace std;
typedef long long int ll;
ll recaman[500001];
map<ll, int> mm;
int main()
{
	int i,x,k;
	recaman[0]=0;
	mm[0]=1;
	for(i=1;i<=500000;i++)
	{
		x=recaman[i-1]-i;
		if(x>0 && mm.find(x)==mm.end())
		{
			mm[x]=1;
			recaman[i]=x;
		}
		else{recaman[i]=recaman[i-1]+i;mm[recaman[i]]=1;}
	}
	scanf("%d",&k);
	while(k!=-1)
	{
		printf("%lld\n",recaman[k]);
		scanf("%d",&k);
	}
	return 0;
}
