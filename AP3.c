#include<stdio.h>
#include<math.h>
int main()
{
	unsigned long long int a3,an_4,Sn,n,a1,d;
	int i,t;
	double root1,root2,D,A,B,C,sum,diff;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a3,&an_4,&Sn);
		sum=a3*1.0+an_4*1.0;
		diff=an_4*1.0-a3*1.0;
		if(diff==0)
		{
			n=Sn/a3;
			printf("%lld\n",n);
			for(i=1;i<=n;i++)
				printf("%lld ",a3);
			printf("\n");
			continue;
		}
		A=sum;
		B=diff-6.0*sum-2.0*Sn;
		C=12.0*Sn;
		D=sqrt(B*B-4*A*C);
		root1=(-B-D)/(2*A);
		root2=(-B+D)/(2*A);
		if(ceil(root1)==floor(root1))
		{
			n=llrintl(root1);
			if((unsigned long long int)diff%(n-6)==0)
			{
				d=(unsigned long long int)diff/(n-6);
				printf("%lld\n",n);
				a1=a3-2*d;
				printf("%lld ",a1);
				for(i=2;i<=n;i++)
				{
					a1+=d;
					printf("%lld ",a1);
				}
				printf("\n");
				continue;
			}
		}
		if(ceil(root2)==floor(root2))
		{
			n=llrintl(root2);
			if((unsigned long long int)diff%(n-6)==0)
			{
				d=(unsigned long long int)diff/(n-6);
				printf("%llu\n",n);
				a1=a3-2*d;
				printf("%llu ",a1);
				for(i=2;i<=n;i++)
				{
					a1+=d;
					printf("%lld ",a1);
				}
				printf("\n");
				continue;
			}
		}
	}
	return 0;
}
