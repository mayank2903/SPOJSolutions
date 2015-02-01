#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	long long int k,num;
	long long int index[]={942,192,442,692};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&k);
		num=ceil(k/4.0)-1;
		printf("%lld\n",num*1000+index[k%4]);
	}
	return 0;
}
/*
192
442
692
992
*/
