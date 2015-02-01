#include<stdio.h>
#include<math.h>
int main()
{
	double sqroot;
	long long int x,num;
	scanf("%lld",&x);
	while(x!=-1)
	{
		sqroot=sqrt(12*x-3);
		if(floor(sqroot)!=ceil(sqroot))
		{
			putchar('N');putchar('\n');
			scanf("%lld",&x);continue;
		}
		else
		{
			num=llrintl(sqroot);
			if(num>=3 && (num-3)%6==0)
			{
				printf("Y\n");
			}
			else printf("N\n");
		}
		scanf("%lld",&x);
	}
	return 0;
}
