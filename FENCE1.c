#include<stdio.h>
int main()
{
	int l;
	float area;
	scanf("%d",&l);
	while(l!=0)
	{
		area=l*l;
		area/=3.1415926f;
		area/=2;
		printf("%.2f\n",area);
		scanf("%d",&l);
	}
	return 0;
}
