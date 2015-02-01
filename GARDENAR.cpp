#include<stdio.h>
#include<math.h>
int main()
{
	double s,s1;
	int t,a,b,c;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		
		s1=a*a+b*b+c*c;
		s=a+b+c;s=s/2.0;
		
		s1=s1*sqrt(3);
		s1=s1/4.0;
		
		s=s*(s-a)*(s-b)*(s-c);
		s=sqrt(s);
		s=s*3.0;
		
		printf("%.2lf\n",(s1+s)/2.0);
	}
	
	return 0;
}
