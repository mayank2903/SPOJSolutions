#include<stdio.h>
#include<math.h>
char str[1000];
int main()
{
	long long int t,n,k,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		k=log2(n+2)-1;
		n=n-(1<<(k+1))+2;
		if(n==0)
		{
			for(i=0;i<k;i++)putchar('6');
			putchar('\n');
		}
		else
		{
			n-=1;
			for(i=k;i>=0;i--)
			{
				str[i]='5'+(n&1);
				n>>=1;
			}
			str[k+1]='\0';
			printf("%s\n",str);
		}
	}
	return 0;
}
