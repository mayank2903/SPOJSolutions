#include<stdio.h>
int main()
{
	int t,a;
	long long int b,d,bb;
	int arr[9][4]={1,0,0,0,
				 2,4,8,6,
				 3,9,7,1,
				 4,6,4,6,
				 5,5,5,5,
				 6,6,6,6,
				 7,9,3,1,
				 8,4,2,6,
				 9,1,9,1
				 };
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&a,&b);
		d=a%10;
		bb=(b-1)%4;
		if(b==0 || d==1){printf("1\n");continue;}
		printf("%d\n",arr[d-1][bb]);
	}
	return 0;
}
