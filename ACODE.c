#include<stdio.h>
#include<string.h>
long long int dp[50001];
int main()
{
	int num,i;
	char str[50001];
	scanf("%s",&str[1]);
	while(str[1]!='0')
	{
		dp[0]=1;
		dp[1]=1;
		for(i=2;str[i]!='\0';i++)
		{
			if(str[i]=='0')dp[i]=dp[i-2];
			else
			{
				num=(str[i-1]-'0')*10+str[i]-'0';
				if(num<=26 && str[i-1]!='0')
					dp[i]=dp[i-1]+dp[i-2];
				else dp[i]=dp[i-1];
			}
		}
		printf("%lld\n",dp[strlen(str+1)]);
		scanf("%s",&str[1]);
	}
	return 0;
}
