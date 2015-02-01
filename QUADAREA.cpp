#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	double s,area,a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		s=(a+b+c+d)/2.0;
		//printf("s=%lf\n",s);
		area=sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n",area);
	}
	return 0;
}
