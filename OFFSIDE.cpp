#include<stdio.h>
#include<algorithm>
using namespace std;
int attack[12],defense[12];
int main()
{
	int a,d,i;
	scanf("%d%d",&a,&d);
	while(a!=0 && d!=0){
	for(i=0;i<a;i++)
	{
		scanf("%d",&attack[i]);
	}
	for(i=0;i<d;i++)
	{
		scanf("%d",&defense[i]);
	}
	sort(attack,attack+a);
	sort(defense,defense+d);
	if(attack[0]<defense[1])
		printf("Y\n");
	else printf("N\n");
	scanf("%d%d",&a,&d);
	}
	return 0;
}
