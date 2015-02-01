#include<stdio.h>
int main()
{
	long int a,b,c;
	while(1)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
		if(a==0 && b==0)break;
		if(b-a==c-b)
		{
			printf("AP %ld\n",c+c-b);
		}
		else if(b/a==c/b)
		{
			printf("GP %ld\n",c*c/b);
		}
	}
	return 0;
}
