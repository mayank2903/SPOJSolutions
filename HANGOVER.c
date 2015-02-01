#include<stdio.h>
int main()
{
	float n,sum;
	int i;
	scanf("%f",&n);
	while(n!=0.0f)
	{
		sum=0;
		for(i=1;;i++)
		{
			sum+=1.0/(i+1);
			if(sum>n)break;
		}
		printf("%d card(s)\n",i);
		scanf("%f",&n);
	}
	return 0;
}
