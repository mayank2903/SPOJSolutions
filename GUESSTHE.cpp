#include<stdio.h>
typedef long long int ll;
ll gc(ll a, ll b)
{
	return (b==0)?a:gc(b,a%b);
}
int main()
{
	char str[50];
	ll i,gcd,lcm,f;
	for(i=0;i<50;i++)str[i]='\0';
	scanf("%s",&str[1]);
	while(str[1]!='*')
	{
		f=0;
		for(i=1;str[i]!='\0';i++)
		{
			if(str[i]=='Y' && f==0)
			{
				gcd=lcm=i;f=1;
			}
			else if(str[i]=='Y')
			{
				//printf("here\n");
				gcd=gc(gcd,i);
				lcm=lcm*i/gcd;
				gcd=lcm;
			}
		}
		f=0;
		for(i=1;str[i]!='\0';i++)
		{
			if(str[i]=='N' && lcm%i==0){f=1;break;}
		}
		if(f)
			printf("-1\n");
		else printf("%lld\n",lcm);
		for(i=0;i<50;i++)str[i]='\0';
		scanf("%s",&str[1]);
	}
	return 0;
}
